# git-test
## 오픈소스SW개론 12223764 윤지우 과제 보고서
### Bash Shell script를 이용해 사용자가 원하는 영화 관련 정보를 제공하는 프로그램 코딩

1. 사용자가 9를 입력할 때까지 계속 돌아가는 반복문 틀 생성
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

