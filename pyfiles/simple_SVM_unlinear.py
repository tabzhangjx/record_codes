from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix

iris = datasets.load_iris()
X = iris.data
y = iris.target
print iris.target_names


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1/3.)

scaler = StandardScaler()
X_train_std = scaler.fit_transform(X_train)
X_test_std = scaler.transform(X_test)


param_grid = {'C':[1e1,1e2,1e3, 5e3,1e4,5e4],
              'gamma':[0.0001,0.0008,0.0005,0.008,0.005,]}
clf = GridSearchCV(svm.SVC(kernel='rbf',class_weight='balanced'),param_grid,cv=10)
clf = clf.fit(X_train_std,y_train)
print clf.best_estimator_

svm.SVC(C=10.0, cache_size=200, class_weight='balanced', coef0=0.0,
  decision_function_shape=None, degree=3, gamma=0.005, kernel='rbf',
  max_iter=-1, probability=False, random_state=None, shrinking=True,
  tol=0.001, verbose=False)

clf.score(X_test_std,y_test)
y_pred = clf.predict(X_test_std)


print(classification_report(y_test,y_pred,target_names=iris.target_names))
print(confusion_matrix(y_test,y_pred,labels=range(iris.target_names.shape[0])))