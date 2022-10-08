#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cwchar>
using namespace std;


#include <stdio.h>
#include <windows.h>
wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;

unsigned char *pField = nullptr;

int nScreenWidth = 80;
int nScreenHeight = 38;

int Rotate(int px, int py, int r){
	switch(r % 4){
		case 0: return py * 4 + px; // 0 degrees
		case 1: return 12 + py -(px * 4); // 90 degrees
		case 2: return 15 - (py * 4) - px; // 180 degrees 
		case 3: return 3 - py + (px * 4);      // 270 degrees
	}
	
	return 0;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY){
	// All Field cells >0 are occupied 
	for (int px = 0; px < 4; px++)
		for (int py = 0; py < 4; py++){
			
			// Get index into piece
			int pi = Rotate(px, py, nRotation);
			
			// Get index into field 
			int fi = (nPosY + py) * nFieldWidth + (nPosX + px);
			
			// check that test is bounds. Note out of bounds does
			// not necessarily mean fail, as the long vertical piece
			// can have cells that lie outside the boundary, so we'll
			// just ignore them 
			
			if (nPosX + px >= 0 && nPosX + px < nFieldWidth){
				if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
				{
					// In Bounds so do collision check 
					if (tetromino[nTetromino][pi] != L'.' && pField[fi] != 0)
						return false; // fail on first hit 
				}
			}
		}
		
		return true;
}
int main(){
	

	// Create assets
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	
	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L"..X.");
	tetromino[1].append(L"....");
	
	tetromino[2].append(L"..X.");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");
	
	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"....");
	
	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");
	
	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");
	
	tetromino[6].append(L"..X.");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");
	
	pField = new unsigned char [nFieldWidth*nFieldHeight];
	for (int x=0; x < nFieldWidth; x++)
		for (int y=0; y < nFieldHeight; y++)
			pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth -1 || y == nFieldHeight -1) ? 9 : 0;
		
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i=0; i<nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	
	bool bkey[4];
	int nCurrentPiece = 0;
	int nCurrentRotation = 0;
	int nCurrentX = nFieldWidth / 2;
	int nCurrentY = 0;
	int nSpeed = 20;
	int nSpeedCount = 0;
	bool bForceDown = false;
	bool bRotateHold = true;
	int nPieceCount = 0;
	int nScore = 0;
	vector<int> vLines;
	bool bGameOver = false;
	
	while(!bGameOver){
		// Timing ===================
		Sleep(20);
		nSpeedCount++;
		bForceDown = (nSpeedCount == nSpeed);
		
		
		//Input ======================
		for (int k = 0; k < 4; k++)
			bkey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;
		
		//Game Logic =======================
		
		
		// Handle player movement
		nCurrentX += (bkey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
		nCurrentX -= (bkey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0;		
		nCurrentY += (bkey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;
		
		
		// Rotate, but latch to stop wild spinning 
		if (bkey[3]){
			
			nCurrentRotation += (bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 :0;
			bRotateHold = false;
		}
		else
			bRotateHold = true;
		
		// Force the piece down the playfiled if it's time 
		if (bForceDown){
			
			// Update difficulty every 50 pieces
			nSpeedCount = 0;
			nPieceCount++;
			if(nPieceCount % 50 == 0)
				if(nSpeed >= 10) nSpeed--;
			
		// Test if piece can be moved down 
		if(DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
			nCurrentY++;   // It can, so do it!
		else
		{
			// It can't Lock the piece in place
			for (int px = 0; px < 4; px++)
				for (int py = 0; py < 4; py++)
					if(tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] !=L'.')
						pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
			
			
			// check for lines
			for (int py = 0; py < 4; py++)
				if(nCurrentY + py < nFieldHeight -1)
				{
					bool bLine = true;
					for (int px = 1; px < nFieldWidth -1; px++)
						bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) !=0;
					
					if (bLine)
					{
						// Remove Line, set to = 
						for (int px = 1; px < nFieldWidth -1 ; px ++)
							bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) != 8;
						vLines.push_back(nCurrentY + py);
						
					}
				}
				nScore += 25;
				if(!vLines.empty())	nScore += (1 << vLines.size()) * 100;

				// Pick New Piece
				nCurrentX = nFieldWidth / 2;
				nCurrentY = 0;
				nCurrentRotation = 0;
				nCurrentPiece = rand() % 7;
				
				// If piece does not fit straight away, game over!
				bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
		}
		}
		
		// Display Field
	for (int x=0; x < nFieldWidth; x++)
		for (int y = 0; y < nFieldHeight; y++)
			screen[(y + 2)*nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y*nFieldWidth + x]];
	
	// Draw Current Piece
		for (int px = 0; px < 4; px++)
			for (int py = 0; py < 4; py++)
				if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] != L'.')
					screen[(nCurrentY + py + 2)*nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
		
	// Draw Score
		snwprintf(&screen[2 * nScreenWidth + nFieldWidth + 6], 16, L"SCORE: %8d", nScore);
	
	// Animate Line Completion
		if (!vLines.empty())
		{
			// Display Frame (cheekily to draw lines)
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
			Sleep(4); // Delay a bit

			for (auto &v : vLines)
				for (int px = 1; px < nFieldWidth - 1; px++)
				{
					for (int py = v; py > 0; py--)
						pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
					pField[px] = 0;
				}

			vLines.clear();
		}
		
	// Display Frame
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	
	}
	
	CloseHandle(hConsole);
	cout << "Game Over!! Score:" << nScore << endl;
	system("pause");
	
	
	return 0;
}