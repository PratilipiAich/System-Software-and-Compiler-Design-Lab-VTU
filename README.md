
# System-Software-and-Compiler-Design-Lab(VTU)

## For Windows Operating System

## How to run?
### Downloads
1. Download [**Flex 2.5.4a**](http://gnuwin32.sourceforge.net/packages/flex.htm)
2. Download [**Bison 2.4.1**](http://gnuwin32.sourceforge.net/packages/bison.htm)
3. Download [**Dev-C++**](https://sourceforge.net/projects/orwelldevcpp/)
### Installations
1. Install **Flex** in **"C:\GnuWin32"** directory
2. Install **Bison** in **"C:\GnuWin32"** directory
3. Install **Dev-C++** in **"C:Dev-Cpp"** directory
### Setting paths
1. Open Environment Variables
2. Add **"C:\GnuWin32\bin"** to path
3. Add **"C:Dev-Cpp\bin"** to path

## Compilation and Execution
1. Open Command Prompt
2. Switch to the directory with the lex (**".l"**) and yacc (**".y"**) files
3. Assume your lex and yacc files to be ***"prog.l"*** and ***"prog.y"***
4. Follow the steps below to compile and execute your program:
		**a) To compile Lex file ONLY:**
				1.  `flex prog.l`
				2. `gcc lex.yy.c`
		**b) To compile both Lex and YACC files:**
				1. `flex prog.l`
				2. `bison -dy prog.y`
				3. `gcc lex.yy.c y.tab.c`
		**c) To execute your program:**
				1. `a.exe`

## Note: To create Lex (".l") and YACC (".y") files download the software [Flex Windows](https://drive.google.com/file/d/0B9D4jOdpRzZHNTVraV9rX280R0E/view) from here. 
This *EditPlus* editor can also be used to compile the Flex and YACC programs.