lab: system architecture and native gateway audit
this is my objective
manual verification of the windows executive architecture, focused on user/kenel mode transitions,process isolation, nd native api mechanics.
this is my env:
im using win11 
client or guest is win11 vm (vmware)
as a connection i used kdnet so i dont mess my machine :)
** in the phase 1 i had to find our target which is "lsass" **

command: !process 0 0 lsass.exe 

the output:
code
Text
PROCESS ffff808e48d98080
    SessionId: none  Cid: 03a0    Peb: fd4da48000  ParentCid: 02f4
    DirBase: 01ff1002  ObjectTable: ffffa98af3c649c0  HandleCount: 1216.
    Image: lsass.exe
research insight:
found the EPROCESS address at ffff808e48d98080 which lives in kernel space nd the PEB address which is fd4da48000 which lives in user space,the DirBase confirms this process has its own unique virtual memory map
** in phase 2 i had to switch into process context ** 

to see the um memory like ntdll i had to move the debugging into the target process
commands:
i did ".process /i /p ffff808e48d98080 "
after that "g" so windbg run in microseconds to bp at the target process
!process -1 0 to verify where are in or at lsass
verification:
code
Text
3: kd> !process -1 0
PROCESS ffff808e48d98080
    Image: lsass.exe
for phase 3 i traced syscall path
i traced how windows is the transition from user mode to kernel mode during a file creation request.
command: u ntdll!NtCreateFile (corrected we cant unassemble ffff808e48d98080 because its the address of the eprocess object if we do u ffff808e48d98080 the dbg will try to decode the data as opcodes and we will see just garbage)
output:
code
Text
ntdll!NtCreateFile:
00007ff8`2e8e3cc0 4c8bd1          mov     r10,rcx
00007ff8`2e8e3cc3 b855000000      mov     eax,55h
00007ff8`2e8e3cc8 f604250803fe7f01 test    byte ptr [SharedUserData+0x308],1
00007ff8`2e8e3cd0 7503            jne     ntdll!NtCreateFile+0x15
00007ff8`2e8e3cd2 0f05            syscall
00007ff8`2e8e3cd4 c3              ret
research insight:
the ssn for NtCreateFile on this win11 build is 0x55.
the syscall is what triggers the hardware to switch from ring3 to ring 0 
security insights since edrs hook the start of ntdll!NtCreateFile i can skip the hook by writing my own assembly that moves 55h into eax and hits syscall directly. this is the "direct syscall" technique.

problems and solutions i had in this lab

unreadable user memory	u ntdll!NtCreateFile failed initially i realized that dbg was in the system context i used .process /i /p to switch to a user process context so i can dissasble our targer 
symbol shadow	ntdll symbols where not loading after the switch i did .reload /user so we force windbg to to load or parse usermode modules
vbs masking	!vbs command was missing so i confirmed vbs is disabled in the vmware this is actually better for this lab as it gives raw visibility of the kernel without vtl 1 masking.
conclusion
so what what i did here is understanding how is the basic win kernel archi and how we move from the um to the kernel

!!! a small about the ssn not every ntdll function  has an ssn 
only functions that are actual syscall stubs !!

