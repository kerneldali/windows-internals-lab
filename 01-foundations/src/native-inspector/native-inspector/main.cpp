#include <stdio.h>
#include "ntnative.h" 

int main() {
    printf("[*] native-inspector starting...\n\n");

    HMODULE ntdll = GetModuleHandleA("ntdll.dll");

    if (!ntdll) {

        printf("ntdll not found :((");
        return -1;

    }

    pNtQuerySystemInformation ntsysinfofunc = (pNtQuerySystemInformation)GetProcAddress(ntdll, "NtQuerySystemInformation");

    ULONG buffsize = 0;

    ntsysinfofunc((SYSTEM_INFORMATION_CLASS)5, NULL, 0, &buffsize);

    buffsize = buffsize + 0x1000;
    PVOID buff = VirtualAlloc(NULL, buffsize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);


    if (ntsysinfofunc((SYSTEM_INFORMATION_CLASS)5, buff, buffsize, NULL) == 0) {
        SYSTEM_PROCESS_INFO* procinfo = (SYSTEM_PROCESS_INFO*)buff;

        printf("address of first struct: %p", procinfo);

        //noww we will loop through the structs and print the pid along with the process name 

        while (true) {
            printf("PID: %d process name: %ls \n", (int)procinfo->UniqueProcessId,procinfo->ImageName.Buffer);
            if (procinfo->NextEntryOffset == 0) break;
            procinfo = ((SYSTEM_PROCESS_INFO*) ((BYTE*)procinfo + procinfo->NextEntryOffset));


        }

        return 0;
    
    }


}