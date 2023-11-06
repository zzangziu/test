#!/bin/bash

echo "--------------------------"
echo "User Name: 윤지우"
echo "Student Number: 12223764"
echo "[ MENU ]"
echo "1. Get the data of the movie identified by a specific 'movie id' from 'u.item'"
echo "2. Get the data of action genre movies from 'u.item'"
echo "3. Get the average 'rating' of the movie identified by specific 'movie id' from 'u.data'"
echo "4. Delete the 'IMDb URL' from 'u.item'"
echo "5. Get the data about users from 'u.user'"
echo "6. Modify the format of 'release date' in 'u.item'"
echo "7. Get the data of movies rated by a specific 'user id' from 'u.data'"
echo "8. Get the average 'rating' of movies rated by users with 'age' between 20 and 29 and 'occupation' as 'programmer'"
echo "9. Exit"
echo "--------------------------"
while true; do
echo "Enter your choice [ 1-9 ]"
read choice

if [[ $choice == 9 ]]; then
echo "Bye!"
exit
fi

case $choice in
1)
echo "Please enter the 'movie id'(1~1682):"
read movie_id

awk -F '|' -v mv_id="$movie_id" '{ if ($1 == mv_id) print $0 }' u.item
;;
2)
echo "Do you want to get the data of 'action' genre movies from 'u.item'?(y/n):"
read ans

if [ "$ans" == "y" ];
then
awk -F '|' '$7 == 1 { print $1, $2 }' u.item | sort -n -k1,1 | head -10
fi
;;

3)
echo "Please enter the 'movie id'(1~1682):"
read movie_id

awk -F '\t' -v mv_id="$movie_id" '$2 == mv_id { sum += $3; cnt++ } END { if (cnt > 0) { avg = sum / cnt; printf "average rating of $movie_id: %.5f\n", avg; }}' u.data
;;

4)
echo "Do you want to delete the 'IMDb URL' from 'u.item'?(y/n):"
read ans

if [ "$ans" = "y" ];
then
sed 's|http[^)]*)||'  u.item | head -10
fi
;;

5)
echo "Do you want to get the data about users from 'u.user'?(y/n):"
read ans

if [ "$ans" = "y" ];
then
sed -n '1,10p' u.user | sed -E 's/([0-9]+)\|([0-9]+)\|M\|(.+)\|(.+)/user \1 is \2 years old male \3/' | sed -E 's/([0-9]+)\|([0-9]+)\|F\|(.+)\|(.+)/user \1 is \2 years old female \3/'
fi
;;

6)
echo "Do you want to Modify the format of 'release data' in 'u.item'?(y/n)"
read ans

if [ "$ans" = "y" ];
then
tail -n 10 u.item | sed -E 's/Jan/01/g; s/Feb/02/g; s/Mar/03/g; s/Apr/04/g; s/May/05/g; s/Jun/06/g; s/Jul/07/g; s/Aug/08/g; s/Sep/09/g; s/Oct/10/g; s/Nov/11/g; s/Dec/12/g; s/([0-9]{2})-([0-9]{2})-([0-9]{4})/\3\2\1/g; s/-//g'
fi
;;

7)
echo "Please enter the 'user id' (1~943):"
read user_id

user_movie=$(awk -F '\t' -v id="$user_id" '$1 == id { print $2 }' u.data | sort -n)

echo "$user_movie" | tr '\n' '|'
echo
echo

movie_list=$(echo "$user_movie" | head -n 10)

for movie_id in $movie_list; do
movie_inf=$(awk -F '|' -v id="$movie_id" '$1 == id { print $1, $2 }' u.item)
echo "$movie_inf"
done
;;

8)
echo "Do you want to get the average 'rating of movies rated by users with 'age' between 20 land 29 and 'occupation' as 'programmer'? (y/n)"
read ans

if [ "$ans" = "y" ]; then
cond_user=$(awk -F "|" '$2 >= 20 && $2 <= 29 && $4 == "programmer" {print $1}' u.user)
for user_id in $cond_user
do
awk -v u_id="$user_id" -F "\t" '$1 == u_id { print $2, $3 }' u.data
done | awk '{ arr[$1]+=$2; cnt[$1]++ } END {for (i in arr) { printf "%s %.5f\n", i, arr[i]/cnt[i]}}' | sort -n
fi
;;
esac
done 

