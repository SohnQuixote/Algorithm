#주석
"나머지 7%%4"
"그냥 몫 7%/%4"
"대입 <-"
"함수 ?"
"찾아보기 ??"
"연속 :"
#데이터 타입 mode
#정숫값 뒤는 L
#NA (데이터 값 X)
#is.na(a) 체크 na.omit(데이터)
#c() 배열
#rep(x, times) x벡터 times만큼 반복
#seq(from,to,by) from부터 to까지 by만큼 증가
#배열 인덱스 첫번째 1
# 벡터끼리 덧셈 곱셈 가능
#list() 딕셔너리
#matrix(data, nrow,ncol,byrow,dimnames) 행렬
#data - 행렬에 저장할 데이터
#nrow - 행 ncol - 열 
#byrow - 행렬 데이터 입력순서 True면 행부터 채움
#dimnames - 행과열의 이름 리스트
#차원 dim
#dim(x) = c(m,n) 차원 변경
#rownames , colnames
#t(x) 전치행렬
#solve(x) 역행렬
# x%*%y 행렬곱
# data.frame(변수명 = 벡터,...)
# 3차원 -> array(data,dim,dimnames)
# Factor - 순서, 명목
# factor(x.levels,labels,ordered) x - 데이터 levels - 가능한 경우의 수 ordered - TRUE -순서형 FALSE - 명목형
# rbind - 합치기 행
# cbind - 합치기 열
# merge - 동일 key 기준 결합 데이터 베이스 join
# if 거의 동일
# ifelse(조건식, 참 명령어, 거짓 명령어)
# switch(변수, 유형 : 명령어 .... ,명령어)
# for(i in 범위)
# while 동일
# repeat 무한 반복 내부에 break 필요
# next 1 증가 continue
# 함수 함수명 = function(패러미터){
  #return (값)
#}

#시각화
# plot 산점도
# hist 히스토그램
# barplot 막대형 그래프
# pie 원그래프
# boxplot 상자수염그림

#barplot(y~x , data) y수치 x 범주
#boxplot(y~x)
#ggplot(data, aesthetics(x,y)) + geom_xxxx()

#scan("") 입력
#read.table(file,header,sep,fill,what) 텍스트
#write.table(x,file)

#read.csv write.csv
#read.dlim tsv
#read_excel()
#write.xlsx()

#전처리
#plyr **ply형태 함수 (d/l/a) -> (d/l/a)
#adply
#ddply
#transform
#dplyr

#%>% 파이프 연산자 함수 연결
#select , arrange...
#select
#filter 조건
#mutate 파생변수 열 추가
#group_by, summarise
#inner_join
#bind_rows,bind_cols
#reshape2
#충돌 -> 라이브러리::함수
# = NULL 결측값 단순삭제
# 단순대치
# na.rm = TRUE 결측치
#파이썬 . -> R $

# 조건 filter

#데이터 유형 변환
#as.***
#scale 정규화 표준화
#표본추출 sample
#createDataPartion 훈련 테스트 나누기
#원하는 행 [a,] 제외 [-a,]
#createFolds
#mean(x,trim,na.rm)
#median
#which 특정값의 위치
#var,sd
#range ,diff
#순위 row_number , min_rank , dense_rank
#table 범주형 데이터 빈도수
#length 길이

#summary,describe,stat.desc

#str 속성
#prop.table addmargins

#상관계수 cor(x,y,method)
#method - pearson ,spearman,kendall
#aggregate(y~x,data,FUN)


#상관계수 시각화 pairs,corrplot
#상관계수 검정 cor.test
#step(object,scope,direction) 변수선택
#formula(step반환값)

#주성분 분석 princomp, prcomp
#biplot 주성분 시각화화
#단순 선형 회귀분석 lm(formula,data)
#로지스틱 회귀분석 glm(formula,family,data)
#혼동행렬 confusion matrix
#auc 모델평가 library("ModelMetrics")
#트레인 모형 -> 인덱스
#다중 공선성 vif car

#예측 predict(model,testdata , type)
#이것을 df as.data.frame
#가끔 잘 안되면 <-
# confusionMatrix(data = 모델후 결과열, reference = 실제결과)
# auc (actual = '실제결과' , predicted = 예측결과)

#의사결정나무 rpart , tree , ctree
# rpart(formula = y~x, data)
#ls 객체 관련정보 벡터반환

#SVM e1071
#svm(formula , data)
#predict(object,data,type)

#KNN knn(train,test,cl = 훈련데이터 종속변수,k) class
#append a = c(a,newdata)

#ANN
#nnet , neuralnet
#nnet(formula, data , size= 은닉층수, maxit = 반복횟수 , decay = 가
#중치 감소모수)

#naiveBayes(formula,data,subset,laplace) e1071

#앙상블 배깅
#bagging adabag
#bagging(formula, data,mfinal,control)

#na 제거 na.omit(데이터셋)

#부스팅
#xgboost xgb.train(params,data,nrounds, early_stopping_rounds,watchlist)
#수치형만 가능
#훈련데이터 xgb.Matrix(data,info)
#list로 매개변수리스트

#랜덤포레스트
#randomForest(formula,data,ntree,mtry)

#k평균
#kmeans(data, centers = k)

#연관분석
#계층적 군집분석
#dist(data,method) 거리 측정

#분석모형 평가
#rmse(actual = 정답 , predicted = 예측값)
#mse

#평가
#confusionMatrix(data = 예측 ,reference = 실제)
#auc(actual,predicted)