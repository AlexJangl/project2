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
    hAppend = CreateFile(TEXT("C:\\GitProject\\project2\\three.txt"), 
        FILE_APPEND_DATA,         
        FILE_SHARE_READ,          
        NULL,                    
        OPEN_ALWAYS,              
        FILE_ATTRIBUTE_NORMAL,    
        NULL);                    

    if (hAppend == INVALID_HANDLE_VALUE)
    {
        printf("Could not open Three.txt.");
        return 0;
    }
    while (ReadFile(hFile, buff, sizeof(buff), &dwBytesRead, NULL)
        && dwBytesRead > 0)
    {
        dwPos = SetFilePointer(hAppend, 0, NULL, FILE_END);
        LockFile(hAppend, dwPos, 0, dwBytesRead, 0);
        WriteFile(hAppend, buff, dwBytesRead, &dwBytesWritten, NULL);
        UnlockFile(hAppend, dwPos, 0, dwBytesRead, 0);
    }
    while (ReadFile(hFileTwo, buff, sizeof(buff), &dwBytesRead, NULL)
        && dwBytesRead > 0)
    {
        dwPos = SetFilePointer(hAppend, 0, NULL, FILE_END);
        LockFile(hAppend, dwPos, 0, dwBytesRead, 0);
        WriteFile(hAppend, buff, dwBytesRead, &dwBytesWritten, NULL);
        UnlockFile(hAppend, dwPos, 0, dwBytesRead, 0);
    }
}


