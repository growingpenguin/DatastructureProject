# DatastructureProject
**1. 문제 소개** <br/>
풀고자 하는 문제 소개<br/>
환경에 있어서 대표적으로 문제시 되는 것 중 하나가 폐기물 처리 비용이다. 어떤 종류의 쓰레기가 과연 가장 폐기 비용이 대표적으로 많이 들까? 따라서 폐기물 처리 비용이 가장 낮은 종류의 쓰레기 종류부터 비용이 가장 높은 쓰레기 종류를 정렬해 알아보고자 한다. <br/>
<br/>
 기대효과: 취합한 작은 데이터베이스 안에서 어떤 종류의 쓰레기가 가장 큰 비용을 소모하고 있는지 알 수 있으며 이런 종류의 쓰레기는 피해야겠다는 인식을 형성할 수 있다.<br/>
해결방안:
Data1.csv,Data2.csv, Friend_Data2.csv 만들기와 finalData.csv로 하나의 csv 파일로 합치기
<br/>
**2. 사용한 데이터 소개** <br/>
Data1.csv(기존의 교수님 주신 column들) 만드는 방법 <br/>
나의 데이터 사진을 보면서 쓰레기별 height, weight, latitude, longtitude, 등 여러 술치 담음 <br/>
Data2.csv(내가 추가하고 싶은  column들) 만드는 방법 <br/>
나의 데이터 사진을 보면서 TrashType을 구분하며 Trashweight를 재거나 유사한 크기의 물체의 무게를 조사해서 csv로 정리 <br/>
 Friend_Data2.csv (내가 추가하고 싶은  column들) 만드는 방법 <br/>
다른 친구들의 데이터 사진을 보면서 TrashType을 구분하며 Trashweight를 재거나 유사한 크기의 물체의 무게를 조사해서 csv로 정리 <br/>
-TrashPrice 값 계산을 위해 아래 통계자료를 바탕으로 TrashType을 정의하고 TrashPrice를 계산하였다 <br/>
통계자료: https://www.recycling-info.or.kr/sds/marketIndex.do?menuNo=M130301 <br/>
<br/>
Data1.csv(기존의 교수님 주신 column들) 용도: <br/>
쓰레기 data 중 한 개의 쓰레기가 담긴 사진을 고르는데 이용되며 각각의 고유한 쓰레기를 정의하는데 (Name의 value들이 다 unique하다) 이용된다. <br/>
Data2.csv 용도:  <br/>
내 데이터의 Trash weight, Price 조사-> 문제 해결  <br/>
Dataclassmate1~20.csv(기존의 교수님 주신 column들) 용도: <br/>
쓰레기 data 중 한 개의 쓰레기가 담긴 사진을 고르는데 이용되며 각각의 고유한 쓰레기를 정의하는데 (Name의 value들이 다 unique하다) 이용된다. <br/>
<br/>
finalData.csv로 하나의 csv 파일로 합치기 <br/>
1. 내 Data를 하나의 dataframe으로 만들기 <br/>
read_csv()함수를 통해 Data1.csv, Data2.csv를 읽어와서 df_mydata1,df_mydata2의  dataframe으로 각각 정의한 후 이들을 "Number"column을 중심으로 merge()해 Example_data라는 하나의 dataframe으로 합침. <br/>
2. 친구들 Data를 하나의 dataframe으로 만들기 <br/>
 read_csv()함수를 통해 다운로드 받은 20개의 친구들 Data.csv를 read_csv()함수를 통해 읽어온 후 쓰레기가 하나인 데이터만 쓰고 싶어서 <br/> 'df_classmatedata1[(df_classmatedata1['Rubbish']+df_classmatedata1['Plastics'] +df_classmatedata1['Cans']+df_classmatedata1['Glass']+df_classmatedata1['Papers'])==1] ' 이러한 방식으로 쓰레기가 하나인 data만 뽑았다.  이 조건에 해당하는 5개의 data를 각각 뽑아 df_classmatedata'번호'_sort의 dataframe으로 저장했다. 그 뒤 friend_df라는 dataframe을 형성해 이 dataframe들을 다 합쳤다.  <br/>
read_csv()함수를 통해 Friend_Data2.csv를 읽어와  friend_df2의 dataframe으로 정의한 후  이들을 "Number"column을 중심으로 merge()해 Example2_data라는 하나의 dataframe으로 합침. <br/>
3. 내 Data, 친구들 Data를 합쳐 하나의 csv 파일로 만들기 <br/>
아까 형성한 Example_data의 dataframe와 Example2_data라는 다른 하나의 dataframe을 concat()함수를 통해 양 옆으로 붙여서 column을 추가한 형태의 dataframe인 Final_data를 만들고 이를 to_csv()함수를 통해 Final_data.csv의 csv파일로 형성한다. <br/>
-merge, concat 함수 : dataframe을 합치는 데 이용됨
<br/>
Attribute 소개: <br/>
TrashName attribute:어떤 쓰레기인지를 구분할 수 있을 만한 이름을 부여 <br/>
-유사한 쓰레기는 겹치지 않게 숫자를 부여하여 이름을 지음 <br/>
TrashWeight attribute: 쓰레기의 무게 <br/>
-단위는 g <br/>
TrashType attribute:  쓰레기의 종류(세부적으로 구분) <br/>
-Ex. Plastic -> PE, PP <br/>
- Trash Type에 따라 TrashPrice를 계산하였기 때문에 TrashType value들은 아래에 언급한 통계자료에 따라 명명 <br/>
 TrashPrice attribute: 쓰레기를 처리하는 데의 비용 <br/>
- 아래의 통계자료를 참고해서 재활용 가능한 쓰레기들의 경우에는 그램 수에 따른 가격으로 환산하여 나타냄 <br/>
-TrashLocation attribute: 쓰레기를 주운 위치 <br/>
-위치는 역명을 기준으로 명명 <br/>
 TrashTransparency attribute: 쓰레기의 투명도 <br/>
-이는 Boolean type으로 나타내며 투명하다면 True, 불투명하다면 False의 value를 지님 <br/>
<br/>
**3. 결과 및 효과(유형 효과, 또는 무형 효과)**
 AVL 트리 <br/>
Trash 클래스(AVL트리1 사용) <br/>
AVL 트리1 용도 <br/>
: 노드의 key를 TrashName으로 설정하여 쓰레기 하나하나를 노드로 접근할 수 있게 AVL트리를 생성하고자 한다. <br/>
AVL 트리2 용도 <br/>
:Trashtype별로 쓰레기 처리 비용 평균 구한 후 어느 종류의 쓰레기가 우리 환경을 가장 해치고 있는지 확인 <br/>
왜 굳이 AVL 트리? <br/>
-트리 노드들이 균등하게 분포해서 탐색 속도를 O(logn)을 유지할 수 있기 때문이다(이진탐색 트리보다 효율적) <br/>
