import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm


np.random.seed(8)
array = np.random.randn(20,2)
X = np.r_[array-[3,3],array+[3,3]]
y = [0]*20+[1]*20

clf = svm.SVC(kernel='linear')
clf.fit(X,y)

svm.SVC(C=1.0, cache_size=200, class_weight=None, coef0=0.0,
  decision_function_shape=None, degree=3, gamma='auto', kernel='linear',
  max_iter=-1, probability=False, random_state=None, shrinking=True,
  tol=0.001, verbose=False)

x1_min, x1_max = X[:,0].min(), X[:,0].max(),
x2_min, x2_max = X[:,1].min(), X[:,1].max(),
xx1, xx2 = np.meshgrid(np.linspace(x1_min, x1_max), np.linspace(x2_min, x2_max))
w = clf.coef_[0]
f = w[0]*xx1 + w[1]*xx2 + clf.intercept_[0]+1
plt.contour(xx1, xx2, f, [0,1,2], colors = 'r')
plt.scatter(X[:,0],X[:,1],c=y,cmap=plt.cm.Paired) 
plt.scatter(clf.support_vectors_[:,0],clf.support_vectors_[:,1],color='k')
plt.show()