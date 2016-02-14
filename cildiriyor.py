N, K  = raw_input().split()
if int(N) >= 1 and int(N) <= 100000 and int(K) >= 1 and int(K) <= 50000:
    Matrix = [[0 for x in range(1)] for x in range(int(N))]
    XOR = [[0 for x in range(2)] for x in range(int(K))]
    Matrix = raw_input().split()
    temp=0
    for i in range(int(K)):
        XOR[i][0],XOR[i][1]= raw_input().split()
    for i in range (int(K)):
        for j in range (int(XOR[i][0])-1,int(XOR[i][1])):
            temp=int(temp)^int(Matrix[j])
        if int(temp) <= 2147483647:
            print int(temp)
            temp=0

