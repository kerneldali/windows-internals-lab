# todo / ideas

### basics
- [ ] get a process list using ntsysinfo (skipping the kernel32)
- [ ] mess around w/ handles in windbg
- [ ] syscall transition logic

### processes
- [ ] manual peb/teb parsing
- [ ] thread hijacking via context
- [ ] check how ppl processes actually block access

### memory
- [ ] walk the vad tree without crashing the system
- [ ] pte flags n page protections
- [ ] build a scanner for rwx regions (basic edr bait)
