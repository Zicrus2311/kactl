# Tests "a.out" against "brute" untill the answers don't match
#  or a.out gets runtime error. whitespace/newline diff are not
#  checked.
# Use "gen" to make random samples. 
# Usage: Keep stress.sh in the same folder as a.out and do:
# > bash stress.sh

for ((i=1;;i++)); do
	./gen > in
	./a.out < in > out || { echo RE; break; }
	./brute < in > ans
	diff -qwbB out ans || { echo WA; break; }
	echo "$i OK"
done
