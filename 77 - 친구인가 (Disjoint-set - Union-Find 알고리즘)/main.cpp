#include <iostream>

using namespace std;
int rootOfEachNode[1001]; /* (�̻�������) �� ������ ��Ʈ ��尡 ���ԵǾ� �ִ� �迭
				  				(����������) �� ������ �θ� ��尡 ���ԵǾ� ���� �� ����
			   				  */

/* �Ű������� ���� ��� v�� ��Ʈ ��带 ��ȯ�ϴ� �Լ� Find(int v)
	 ���̺��� ��Ʈ ��尡 �ƴ� �θ� ��尡 ��ϵǾ� ���� ���� �ִµ�
	 �̶��� ��Ʈ ������ Ÿ�� �ö󰡸鼭 �� ����� �θ� ��带 ��Ʈ ���� ���� */
int Find(int v){
	if(v==rootOfEachNode[v]) return v;
	/* ��Ʈ���� Ÿ�� �ö󰡼� ��ȣ�� �������
		�� ����� �θ� ��带 ��Ʈ ���� ���� */
	else return rootOfEachNode[v]=Find(rootOfEachNode[v]); 
}

/* �� ��带 ���� ���� Ʈ��(����)�� �����ϴ� �Լ� Union(int a, int b)
	 ���� �ٸ� Ʈ���� ���� ���� ù��° ��带 �ι�° ����� �ڽ� ���� �� */
void Union(int firstNode, int secondNode){
	int rootOfFirstNode = Find(firstNode);
	int rootOfSecondNode = Find(secondNode);
	/* �� ��尡 ���� �ٸ� ���տ� ���� ���, 
	�ι�° ����� ��Ʈ ��带 ù��° ����� ��Ʈ ���� ���� 
	�׷��� �� ��尡 ���� Ʈ���� �������� ��
	*/
	if(rootOfFirstNode != rootOfSecondNode) 
		rootOfEachNode[rootOfFirstNode] = rootOfSecondNode;
}

int main(){
	// freopen("input.txt", "rt", stdin);
	int n, m;
	cin >> n >> m;
	
	// ��� �ϳ��� ���Ұ� �ϳ��� ������ �������� ���� unf �迭�� �ʱ�ȭ 
	for(int i = 1; i <= n; i++){
		rootOfEachNode[i]=i;
	}
	
	// �� ��带 ���� Ʈ���� ������
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
