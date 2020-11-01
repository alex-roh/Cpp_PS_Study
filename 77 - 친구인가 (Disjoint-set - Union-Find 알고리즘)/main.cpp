#include <iostream>

using namespace std;
int rootOfEachNode[1001]; /* (이상적으로) 각 노드들의 루트 노드가 기입되어 있는 배열
				  				(현실적으로) 각 노드들의 부모 노드가 기입되어 있을 수 있음
			   				  */

/* 매개변수로 들어온 노드 v의 루트 노드를 반환하는 함수 Find(int v)
	 테이블에는 루트 노드가 아닌 부모 노드가 기록되어 있을 수도 있는데
	 이때는 루트 노드까지 타고 올라가면서 각 노드의 부모 노드를 루트 노드로 변경 */
int Find(int v){
	if(v==rootOfEachNode[v]) return v;
	/* 루트까지 타고 올라가서 번호를 얻었으면
		각 노드의 부모 노드를 루트 노드로 변경 */
	else return rootOfEachNode[v]=Find(rootOfEachNode[v]); 
}

/* 두 노드를 서로 같은 트리(집합)에 연결하는 함수 Union(int a, int b)
	 서로 다른 트리에 있을 때는 첫번째 노드를 두번째 노드의 자식 노드로 함 */
void Union(int firstNode, int secondNode){
	int rootOfFirstNode = Find(firstNode);
	int rootOfSecondNode = Find(secondNode);
	/* 두 노드가 서로 다른 집합에 있을 경우, 
	두번째 노드의 루트 노드를 첫번째 노드의 루트 노드로 만듦 
	그러면 두 노드가 속한 트리는 합쳐지게 됨
	*/
	if(rootOfFirstNode != rootOfSecondNode) 
		rootOfEachNode[rootOfFirstNode] = rootOfSecondNode;
}

int main(){
	// freopen("input.txt", "rt", stdin);
	int n, m;
	cin >> n >> m;
	
	// 노드 하나를 원소가 하나인 각각의 집합으로 보고 unf 배열을 초기화 
	for(int i = 1; i <= n; i++){
		rootOfEachNode[i]=i;
	}
	
	// 두 노드를 같은 트리에 연결함
	int firstNode, secondNode;
	for(int i = 1; i <= m; i++){
		cin >> firstNode >> secondNode;
		Union(firstNode, secondNode);
	}
	
	cin >> firstNode >> secondNode;
	
	int rootOfFirstNode, rootOfSecondNode;
	
	rootOfFirstNode = Find(firstNode);
	rootOfSecondNode =Find(secondNode);
	
	if(rootOfFirstNode == rootOfSecondNode) cout << "YES";
	else cout << "NO";
	
	return 0;
}
