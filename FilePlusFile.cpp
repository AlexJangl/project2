#include <iostream>
#include <windows.h>

int main()
{
    HANDLE hFile;
    HANDLE hFileTwo;
    HANDLE hAppend;
    DWORD  dwBytesRead, dwBytesWritten, dwPos;
    BYTE   buff[4096];

    hFile = CreateFile(TEXT("C:\\GitProject\\project2\\one.txt"), 
        GENERIC_READ,             
        0,                        
        NULL,                     
        OPEN_EXISTING,            
        FILE_ATTRIBUTE_NORMAL,    
        NULL);                    

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Could not open One.txt.");
        return 0;
    }

    hFileTwo = CreateFile(TEXT("C:\\GitProject\\project2\\two.txt"), 
        GENERIC_READ,             
        0,                        
        NULL,                     
        OPEN_EXISTING,            
        FILE_ATTRIBUTE_NORMAL,    
        NULL);                    

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Could not open Two.txt.");
        return 0;
    }
    
}


