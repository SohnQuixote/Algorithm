#�ּ�
"������ 7%%4"
"�׳� �� 7%/%4"
"���� <-"
"�Լ� ?"
"ã�ƺ��� ??"
"���� :"
#������ Ÿ�� mode
#������ �ڴ� L
#NA (������ �� X)
#is.na(a) üũ na.omit(������)
#c() �迭
#rep(x, times) x���� times��ŭ �ݺ�
#seq(from,to,by) from���� to���� by��ŭ ����
#�迭 �ε��� ù��° 1
# ���ͳ��� ���� ���� ����
#list() ��ųʸ�
#matrix(data, nrow,ncol,byrow,dimnames) ���
#data - ��Ŀ� ������ ������
#nrow - �� ncol - �� 
#byrow - ��� ������ �Է¼��� True�� ����� ä��
#dimnames - ������� �̸� ����Ʈ
#���� dim
#dim(x) = c(m,n) ���� ����
#rownames , colnames
#t(x) ��ġ���
#solve(x) �����
# x%*%y ��İ�
# data.frame(������ = ����,...)
# 3���� -> array(data,dim,dimnames)
# Factor - ����, ���
# factor(x.levels,labels,ordered) x - ������ levels - ������ ����� �� ordered - TRUE -������ FALSE - �����
# rbind - ��ġ�� ��
# cbind - ��ġ�� ��
# merge - ���� key ���� ���� ������ ���̽� join
# if ���� ����
# ifelse(���ǽ�, �� ��ɾ�, ���� ��ɾ�)
# switch(����, ���� : ��ɾ� .... ,��ɾ�)
# for(i in ����)
# while ����
# repeat ���� �ݺ� ���ο� break �ʿ�
# next 1 ���� continue
# �Լ� �Լ��� = function(�з�����){
  #return (��)
#}

#�ð�ȭ
# plot ������
# hist ������׷�
# barplot ������ �׷���
# pie ���׷���
# boxplot ���ڼ����׸�

#barplot(y~x , data) y��ġ x ����
#boxplot(y~x)
#ggplot(data, aesthetics(x,y)) + geom_xxxx()

#scan("") �Է�
#read.table(file,header,sep,fill,what) �ؽ�Ʈ
#write.table(x,file)

#read.csv write.csv
#read.dlim tsv
#read_excel()
#write.xlsx()

#��ó��
#plyr **ply���� �Լ� (d/l/a) -> (d/l/a)
#adply
#ddply
#transform
#dplyr

#%>% ������ ������ �Լ� ����
#select , arrange...
#select
#filter ����
#mutate �Ļ����� �� �߰�
#group_by, summarise
#inner_join
#bind_rows,bind_cols
#reshape2
#�浹 -> ���̺귯��::�Լ�
# = NULL ������ �ܼ�����
# �ܼ���ġ
# na.rm = TRUE ����ġ
#���̽� . -> R $

# ���� filter

#������ ���� ��ȯ
#as.***
#scale ����ȭ ǥ��ȭ
#ǥ������ sample
#createDataPartion �Ʒ� �׽�Ʈ ������
#���ϴ� �� [a,] ���� [-a,]
#createFolds
#mean(x,trim,na.rm)
#median
#which Ư������ ��ġ
#var,sd
#range ,diff
#���� row_number , min_rank , dense_rank
#table ������ ������ �󵵼�
#length ����

#summary,describe,stat.desc

#str �Ӽ�
#prop.table addmargins

#������ cor(x,y,method)
#method - pearson ,spearman,kendall
#aggregate(y~x,data,FUN)


#������ �ð�ȭ pairs,corrplot
#������ ���� cor.test
#step(object,scope,direction) ��������
#formula(step��ȯ��)

#�ּ��� �м� princomp, prcomp
#biplot �ּ��� �ð�ȭȭ
#�ܼ� ���� ȸ�ͺм� lm(formula,data)
#������ƽ ȸ�ͺм� glm(formula,family,data)
#ȥ����� confusion matrix
#auc ���� library("ModelMetrics")
#Ʈ���� ���� -> �ε���
#���� ������ vif car

#���� predict(model,testdata , type)
#�̰��� df as.data.frame
#���� �� �ȵǸ� <-
# confusionMatrix(data = ���� �����, reference = �������)
# auc (actual = '�������' , predicted = �������)

#�ǻ�������� rpart , tree , ctree
# rpart(formula = y~x, data)
#ls ��ü �������� ���͹�ȯ

#SVM e1071
#svm(formula , data)
#predict(object,data,type)

#KNN knn(train,test,cl = �Ʒõ����� ���Ӻ���,k) class
#append a = c(a,newdata)

#ANN
#nnet , neuralnet
#nnet(formula, data , size= ��������, maxit = �ݺ�Ƚ�� , decay = ��
#��ġ ���Ҹ��)

#naiveBayes(formula,data,subset,laplace) e1071

#�ӻ�� ���
#bagging adabag
#bagging(formula, data,mfinal,control)

#na ���� na.omit(�����ͼ�)

#�ν���
#xgboost xgb.train(params,data,nrounds, early_stopping_rounds,watchlist)
#��ġ���� ����
#�Ʒõ����� xgb.Matrix(data,info)
#list�� �Ű���������Ʈ

#����������Ʈ
#randomForest(formula,data,ntree,mtry)

#k���
#kmeans(data, centers = k)

#�����м�
#������ �����м�
#dist(data,method) �Ÿ� ����

#�м����� ��
#rmse(actual = ���� , predicted = ������)
#mse

#��
#confusionMatrix(data = ���� ,reference = ����)
#auc(actual,predicted)