import math
def cos(x):
	x=x*2*math.pi/360
	if x < 0:
		label = -1
	else:
		label =1
	while (x < 0 or x > 2*math.pi):
		x-=label*2*math.pi
	print(x)
	a=1
	b=1
	cosx=1
	for i in range(20):
		#print("i")
		#print(i)
		#print(cosx)
		a=(-1)*a*x*x/(b*(2*i+1)*(2*i+2))
		#print("a")
		#print(a)
		cosx+=a
	print(cosx)


cos(180)
cos(360)
cos(90)
cos(20)