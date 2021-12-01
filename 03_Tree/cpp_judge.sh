g++ 1.cpp -o my_code.out
g++ right.cpp -o right_code.out
g++ test_maker.cpp -o test_maker.out

for i in {1..250}
do
    ./test_maker.out > test.txt
    ./my_code.out < test.txt > my_ans.txt
    ./right_code.out < test.txt > right_ans.txt
    diff -w -B my_ans.txt right_ans.txt > diff.txt
    if [ -s diff.txt ]
    then
        echo "Wrong On test $i"
        exit 0
    else
        echo "Accept On test $i"
    fi
    sleep 1
done