def ebob(a,b):
	while b:
		a,b=b,a%b;
	return a;

N, K  = raw_input().split()

if  (0 < int(N)) and (int(N) <= 40000) and (0 < int(K)) and (int(K) <= int(N)):
		
	veri = [[0 for x in range(2)] for x in range(int(N))]
	
	git = 0

	for i in range(0,int(N)):
		veri[i][0], veri[i][1] = raw_input().split()
		if (int(veri[i][0]) > 10000 ) or (int(veri[i][1]) > 10000):
			git = 1


	if git == 0:

		for i in range(0,int(N)):
			sayac = 0
			for k in range(i+1,int(N)):
				x=ebob(int(veri[i][0]),int(veri[k][0]))
				y=ebob(int(veri[i][1]),int(veri[k][1]))

				if int(veri[i][1])==y or int(veri[k][1])==y:
					
					if  int(veri[i][0])==x or int(veri[k][0])==x:
						sayac = int(sayac) + 1

			if int(sayac) >= int(K):
				print "Yes"
				break


		