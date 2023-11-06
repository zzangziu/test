## 오픈소스SW개론 12223764 윤지우 과제 보고서
### Bash Shell script를 이용해 사용자가 원하는 영화 관련 정보를 제공하는 프로그램 코딩

1. 사용자가 9를 입력할 때까지 계속 돌아가는 반복문 틀을 생성하였다. if문을 사용해 9가 입력으로 들어오면 검사하지 않고 바로 끝내도록 했다.
사용자가 9를 입력할 경우 'bye' 출력 후 exit
```linux
while true; do
echo "Enter your choice [ 1-9 ]"
read choice

if [[ $choice == 9 ]]; then
echo "Bye!"
exit
fi
```

case를 이용해  1부터 8까지 숫자가 choice를 통해 들어왔을 때 각 숫자에 맞는 기능 하도록 구현

1. u.item에서 원하는 movie id를 입력하면 정보를 출력하는 기능
awk를 사용하여 한 줄 전체를 출력하는 $0으로 item 파일 내에서 영화 정보 모두 출력해주었다.
```linux
1)
echo "Please enter the 'movie id'(1~1682):"
read movie_id

awk -F '|' -v m_id="$movie_id" '{ if ($1 == m_id) print $0 }' u.item
;;
```

2. item 파일에서 액션 장르의 영화를 오름차순으로 10개까지만 출력하는 기능
   사용자가 y를 입력했을 경우에 액션 장르의 영화를 movie id 기준 오름차순으로 10개까지 출력한다.
awk를 이용해 movie id와 movie title만 출력되도록 하고, sort를 이용해 정렬한 후 head를 이용해 위에서부터 10개까지만 출력되도록 구현히였다.
```linux
2)
echo "Do you want to get the data of 'action' genre movies from 'u.item'?(y/n):"
read ans

if [ "$ans" == "y" ];
then
awk -F '|' '$7 == 1 { print $1, $2 }' u.item | sort -n -k1,1 | head -10
fi
;;
```

3. 사용자에게 movie id를 입력받고 해당 영화의 평점을 전부 합산하여 평균 도출하는 기능
데이터 파일에서 awk를 사용하여 movie id가 사용자 입력 id와 같으면 $3(rating)을 합산하는 동시에 count 변수를 증가시키고, 파일을 모두 검사한 후 합산된 값을 count 값으로 나누어 소수점 6번째 자리에서 rounding 구현하였다.

```linux
3)
echo "Please enter the 'movie id'(1~1682):"
read movie_id

awk -F '\t' -v id="$movie_id" '$2 == id { sum += $3; count++ } END { if (count > 0) { avg = sum / count; printf "average rating of $movie_id: %.5f\n", avg; }}' u.data
;;
```

4. IMDb URL 삭제 후 10개 영화 출력
URL의 경우 모두 http로 시작하여 )로 끝나기 때문에 해당 부분을 sed를 이용해 잘라내고 출력할 수 있도록 하였다. 사용자가 y를 입력할 경우 URL을 잘라낸 후 movie id 기준 1번부터 10번까지 head를 이용해 위에서부터 출력한다.

```linux
4)
echo "Do you want to delete the 'IMDb URL' from 'u.item'?(y/n):"
read ans

if [ "$ans" = "y" ];
then
sed 's|http[^)]*)||'  u.item | head -10
fi
;;
```

5. 유저 데이터를 이용해 유저 정보 접근
사용자가 y를 입력할 경우 user id와 age, occupation을 출력 양식에 맞게 출력하고 gender의 경우 sed를 이용해 F일 때 female로, M일 때 male로 바뀌도록 설정하였다. 

```linux
5)
echo "Do you want to get the data about users from 'u.user'?(y/n):"
read ans

if [ "$ans" = "y" ];
then
sed -n '1,10p' u.user | sed -E 's/([0-9]+)\|([0-9]+)\|M\|(.+)\|(.+)/user \1 is \2 years old male \3/' | sed -E 's/([0-9]+)\|([0-9]+)\|F\|(.+)\|(.+)/user \1 is \2 years old female \3/'
fi
;;
```

6. 아이템 파일을 통해 날짜 출력 양식 변경해주는 기능
사용자가 y를 입력할 경우 sed를 이용해 앞의 두자리와 뒤의 네자리의 위치를 변경해주고 하이픈을 삭제해주었다. 알파벳으로 표시된 달의 경우도 마찬가지로 sed를 이용해 하나하나 12월까지 모두 대치시켜서 변경해주었다. 또한 가장 마지막 10개를 출력해 줘야 하기 때문에 tail을 사용하여 마지막 10개를 출력할 수 있도록 하였다.

```linux
6)
echo "Do you want to Modify the format of 'release data' in 'u.item'?(y/n)"
read ans

if [ "$ans" = "y" ];
then
tail -n 10 u.item | sed -E 's/Jan/01/g; s/Feb/02/g; s/Mar/03/g; s/Apr/04/g; s/May/05/g; s/Jun/06/g; s/Jul/07/g; s/Aug/08/g; s/Sep/09/g; s/Oct/10/g; s/Nov/11/g; s/Dec/12/g; s/([0-9]{2})-([0-9]{2})-([0-9]{4})/\3\2\1/g; s/-//g'
fi
;;
```

7. 유저 아이디를 이용해 해당 유저가 평가한 모든 영화를 출력해주는 기능
사용자에게 user id를 입력받고 awk를 이용해 해당 유저가 평가한 영화를 찾아내고 sort로 오름차순으로 정렬하여 user_movie에 저장하고, 이대로 출력하면 한 줄에 한 movie id가 나오기 때문에 tr을 이용해서 '\n' 대신 '|'을 사용하여 출력해 주었다. 또한 user_movie로 for문을 돌려 movie id 기준 상위 10개의 movie id에 대해 u.item에서 movie id와 movie title을 가져와 형식에 맞게 출력하도록 하였다. 

```linux
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
```

8. 사용자 중 20대 프로그래머가 평가한 영화만을 찾아 20대 프로그래머의 영화 평점 평균을 출력하는 기능
사용자가 y를 입력할 경우 cond_user에 조건에 맞는 20대 프로그래머의 user_id를 u.user 파일에서 찾아 저장하고, for 문을 돌려 u.data 파일에서 해당 user id가 평가한 영화의 rating을 이용해 평점 평균을 소수점 5번째 자리까지 출력해 주었다.
```Linux
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
```

