# \# todo / ideas

# 

# \### the basics (foundations)

# \- \[x] get a process list using ntsysinfo (skipping the kernel32)

# \- \[ ] remote kernel debugging setup (kdnet / vmware)

# \- \[ ] find syscall numbers (SSNs) for core ntdll functions

# 

# \### execution mechanics (processes n threads)

# \- \[ ] manual peb/teb parsing (finding loaded dlls without APIs)

# \- \[ ] research ppl (protected process light) flags on lsass.exe

# \- \[ ] trace createprocess internal stages in windbg

# \- \[ ] thread hijacking via context manipulation (SetThreadContext)

# 

# \### memory internals

# \- \[ ] walk the vad tree without crashing the system

# \- \[ ] pte flags n page protections (rx vs rwx)

# \- \[ ] build a scanner for rwx regions (basic edr bait)

# \- \[ ] manual mapping a dummy dll into memory

