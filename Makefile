all: accountant inserter calculate

main: accountant.c
	$gcc accountant.c -o accountant

insert: inserter.c
	$gcc inserter.c -o inserter

calculate: calculate.c
	$gcc calculate.c -o calculate

