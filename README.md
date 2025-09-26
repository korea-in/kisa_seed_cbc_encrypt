# kisa_seed_cbc_encrypt
한국인터넷진흥원(KISA)에서 개발한 SEEND 암호화 방식을 활용하여 문자열 암복호화하는 프로그램
CBC 운영 방식을 사용함

## 주요 변수
- pbszUserKey
- pbszIV
- plainText
- pbszCipherText
- pbszPlainText

이 프로젝트는 BFS(Breadth-First Search, 너비 우선 탐색) 알고리즘을 활용하여 
시작점에서 목표 지점까지 최단 경로를 찾는 과정을 시각적으로 보여주는 프로그램입니다.  
사용자는 격자(Grid) 위에서 출발점, 도착점, 장애물을 설정하고,
알고리즘이 어떻게 경로를 탐색하는지 단계별로 확인할 수 있습니다.  

주요 기능:
- 격자(Grid) 기반의 경로 탐색 시각화
- BFS 알고리즘의 탐색 과정 애니메이션
- 출발/도착 지점 및 장애물 직접 설정
- 최단 거리 및 경로 표시


컴파일 시 KISA_SEED_CBC.c main.c를 함께 컴파일해야함.
gcc -o main KISA_SEED_CBC.c main.c
