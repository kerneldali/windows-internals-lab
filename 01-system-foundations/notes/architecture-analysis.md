# foundations: ntdll nd architecture research

### why this tool
standard win32 apis (kernel32) are too high level and easy for edrs to hook. i built this to talk with the ntdll directly. if i can get the process list via ntsysinfo im skipping the documented layer.

### what i learned coding this:
- **probe nd allocate**: windows wont tell u how big the list is. u gotta call it w/ 0, get the size, then allocate. i added 0x1000 padding because the os is busy and the list grows fast so 0x1000 is a reasonable size:) .
- **pointer math is a bitch**: if u dont cast to(BYTE*) before adding the offset, the compiler multiplies the jump by the struct size and u crash liek for example lets say we are at the firt struct
and the struct size is 0x200 the compiler will mutiply it like iths (0x200*(nextoffset)+currentaddy) this will cause a crash so we tell the compiler to suppose that the size of the struct is 1 byte by doing (BYTE*) . 
- **unicode strings**: kernel uses 2-byte chars. needed %ls n wprintf to actually see the names instead of just the first letter.

i found these in my output:
- **lsass.exe**: which holds the credentials. 
- **csrss.exe**: which knows about every process in the session.
- **smss.exe**: what starts everything.