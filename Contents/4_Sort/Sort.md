# 정렬

<br>

## 버블 정렬
> 데이터의 인접 요소끼리 비교하고 swap 연산을 수행하며 정렬하는 방식

- 버블 정렬은 두 인접한 데이터의 크기를 비교해 정렬하는 방법이다
- 간단하게 구현할 순 있지만 시간 복잡도는 $O(n^2)$으로 다른 정렬 알고리즘보다 속도가 느린 편이다

<br>

### 버블 정렬 과정
1. 비교 연산이 필요한 루프 범위를 설정한다
2. 인접한 데이터 값을 비교한다
3. swap 조건에 부합하면 swap 연산을 수행한다
4. 루프 범위가 끝날 때까지 2~3을 반복한다
5. 정렬된 영역을 설정한다. 다음 루프를 실행할 때는 이 영역을 제외한다
6. 비교 대상이 없을 때까지 1~5를 반복한다

<br>

<details>
    <summary> 알고리즘(ADL) </summary>
    <div markdown="0">
    <img src="./Images/Bubble_ADL.png" width = 600>
    </div>
</details>

<br>

## 선택 정렬
> 대상에서 가장 크거나 작은 데이터를 찾아가 선택을 반복하면서 정렬하는 방식

- 선택정렬은 대상 데이터에서 최대나 최소 데이터를 나열된 순으로 찾아가며 선택하는 방법
- 구현이 복잡하고 시간 복잡도도 $O(n^2)$으로 비효율적이다

<br>

### 선택 정렬 과정
1. 남은 정렬 부분에서 최솟값 또는 최댓값을 찾는다
2. 남은 정렬 부분에서 가장 앞에 있는 데이터와 선택된 데이터를 swab한다.
3. 가장 앞에 있는 데이터의 위치를 변경해(index++) 남은 정렬 부분위 범위를 축소한다
4. 전체 데이터 크기만큼 index가 커질 때까지, 즉 남은 정렬 부분이 없을때까지 반복한다.

<br>

<details>
    <summary> 알고리즘(ADL) </summary>
    <div markdown="0">
    <img src="./Images/Selection_ADL.png" width = 600>
    </div>
</details>

<br>

## 삽입 정렬
> 대상을 선택해 정렬된 영역에서 선택 데이터의 적절한 위치를 찾아 삽입하면서 정렬하는 방식

- 이미 정렬된 데이터 범위에 정렬되지 않은 데이터를 적절한 위치에 삽입해 정렬하는 방식
- 시간 복잡도가 $O(n^2)$으로 느린 편이지만 구현은 쉽다

<br>

### 삽입 정렬 수행 방식
1. 현대 index에 있는 데이터 값을 선택한다
2. 현재 선택한 데이터가 정렬된 데이터 범위에 삽입될 위치를 탐색한다.
3. 삽입 위치부터 index에 있는 위치까지 shift 연산을 수행한다
4. 삽입 위치에 현재 선택한 데이터를 삽입하고 index++ 연산을 수행한다
5. 전체 데이터의 크기만큼 index가 커질 때까지, 즉 선택할 데이터가 없을 때까지 반복한다.

<br>

<details>
    <summary> 알고리즘(ADL) </summary>
    <div markdown="0">
    <img src="./Images/Insertion_ADL.png" width = 600>
    </div>
</details>

<br>

### ***적절한 삽입 위치를 탐색하는 부분에서 이진 탐색등과 같은 탐색 알고리즘을 사용하면 시간 복잡도를 줄일 수 있다***

<br>

## 퀵 정렬
> pivot 값을 선정해 해당 값을 기준으로 정렬하는 방식

- 퀵 정렬은 기준값을 설정해 해당 값보다 작은 데이터와 큰 데이터로 분류하는 것을 반복해 정렬하는 알고리즘
- 기준값이 어떻게 선정되는지가 시간 복잡도에 많은 영향을 미친다
- 평균 시간 복잡도는 $O(nlogn)$이며 최악의 경우는 $O(n^2)$ 이다

<br>

### 퀵 정렬 과정
1. 데이터를 분할하는 vipot을 설정한다
2. pivot을 기준으로 다음 1~5 과정을 거쳐 데이터를 2개의 집합으로 분리한다
    1. start가 가르키는 데이터가 pivot이 가르키는 데이터보다 작으면 start를 오른쪽으로 1칸 이동한다
    2. end가 가리키는 데이터가 pivot이 가리키는 데이터보다 크면 end를 왼쪽으로 1칸 이동한다
    3. start가 가리키는 데이터가 pivot이 가리키는 데이터보다 크고, end가 가리키는 데이터가 pivot이 가리키는 데이터보다 작으면 start, end가 가리키는 데이터를 swap하고 start는 오른쪽, end는 왼쪽으로 1칸씩 이동한다
    4. start와 end가 만날 때까지 1~3을 반복한다
    5. start와 end가 만나면 만난 지점에서 가리키는 데이터와 pivot이 가리키는 데이터를 비교하여 pivot이 가리키는 데이터가 크면 만난 지점의 오른쪽에, 작으면 만난 지점의 왼쪽에 pivot이 가리키는 데이터를 삽입한다
3. 분리 집합에서 각각 다시 pivot을 선정한다
4. 분리 집합이 1개 이하가 될 때까지 과정 1~3을 반복한다

<br>

<details>
    <summary> 알고리즘(ADL) </summary>
    <div markdown="0">
    <img src="./Images/Quick_ADL1.png" width = 600>
    <img src="./Images/Quick_ADL2.png" width = 600>
    </div>
</details>

<br>

<details>
    <summary>수행 과정(png)</summary>
    <div markdown="0">
    <img src="./Images/Quick_Process1.png" width = 600>
    <img src="./Images/Quick_Process2.png" width = 600>
    <img src="./Images/Quick_Process3.png" width = 600>
    <img src="./Images/Quick_Process4.png" width = 600>
    </div>
</details>

<br>

<details>
    <summary>수행 과정(gif)</summary>
    <div markdown="0">
    <img src="./Images/Quick.gif" width = 600>
    </div>
</details>

<br>

## 병합 정렬
> 이미 정렬된 부분 집합들을 효율적으로 병합해 전체를 정렬하는 방식

- 병합 정렬은 분할 정복 방식을 사용해 데이터를 분할하고 분할한 집합을 정렬하며 합치는 알고리즘
- 시간 복잡도는 $O(nlogn)$ 이다

<br>

<details>
    <summary> 알고리즘(ADL) </summary>
    <div markdown="0">
    <img src="./Images/Merge_ADL1.png" width = 600>
    <img src="./Images/Merge_ADL2.png" width = 600>
    </div>
</details>

<br>

<details>
    <summary> 수행 과정(PNG) </summary>
    <div markdown="0">
    <img src="./Images/Merge_Process.png" width = 600>
    </div>
</details>

<br>

<details>
    <summary> 수행 과정(GIF) </summary>
    <div markdown="0">
    <img src="./Images/Merge.gif" width = 600>
    </div>
</details>

<br>

## 기수 정렬
> 데이터의 자릿수를 바탕으로 비교해 데이터를 정렬하는 방식

<details>
    <summary>수행과정</summary>
    <div markdown="0">
    <img src="./Images/RadixSort.png" width = 600>
    </div>
</details>