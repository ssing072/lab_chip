# Test file for lab_chip


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Add tests below

test "INCREASE ONCE: PINA: 0x01, 0x00 => PORTC: 8, state = WAIT"
set state = INIT
setPINA 0x01
continue 2
setPINA 0x00
continue 2
expectPORTC 8
expect state WAIT
checkResult


test "INCREASE 3 more times: PINA: 0x01, 0x00, 0x01, 0x00, 0x01, 0x00 => PORTC: 9, state = WAIT"
set state = INIT
setPINA 0x01
continue 2
setPINA 0x00
continue 2
setPINA 0x01
continue 2
setPINA 0x00
continue 2
setPINA 0x01
continue 2
setPINA 0x00
continue 2
expectPORTC 9
expect state WAIT
checkResult

test "Decrease once: PINA: 0x02, 0x00 => PORTC: 8, state = WAIT"
set state = INIT
setPINA 0x02
continue 2
setPINA 0x00
continue 2
expectPORTC 8
expect state WAIT
checkResult

test "RESET to 0: PINA: 0x01, 0x02, 0x00 => PORTC: 0, state = WAIT"
set state = INIT
setPINA 0x01
continue 2
setPINA 0x02
continue 2
setPINA 0x00
continue 2
expectPORTC 0
expect state WAIT
checkResult

test "DECREASE at 0: PINA: 0x02, 0x00 => PORTC: 0, state = WAIT"
set state = INIT
setPINA 0x02
continue 2
setPINA 0x00
continue 2
expectPORTC 0
expect state WAIT
checkResult

test "INCREASE at 0: PINA: 0x01, 0x00 => PORTC: 1, state = WAIT"
set state = INIT
setPINA 0x01
continue 2
setPINA 0x00
continue 2
expectPORTC 1
expect state WAIT
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
