# MustGo_Raspberry
라즈베리파이에서 cloud의 db와 통신하여 
1. 로봇을 등록
2. 가야할 경로가 있는지 확인 후 있다면 return 
3. 위도 경도 좌표를 계산하여 direction과 distance 값을 가진 struct의 array를 생성
4. pthread를 통해 해당 array 를 순차적으로(비동기적으로) uart(/dev/ttyS0)를 이용하여 STM32와 통신


# Prerequisite
1. make curl
'''
./config
make
'''
2. build
    '''
    cd ~/MustGo_Raspberry/build
    cmake ..
    make
    '''