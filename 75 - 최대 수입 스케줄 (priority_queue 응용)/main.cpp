#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std; 

struct Task {
	Task(int m, int d){
		M = m;
		D = d;
	}
	int M;
	int D;
};

bool lateDayFirstOrder(const Task& first, const Task& second){
	
	if(first.D == second.D) 
		return (first.M > second.M) ? true : false;
	else 
		return (first.D > second.D) ? true : false;
	
}

ostream& operator<<(ostream& os, const Task& task)
{
    os << "Task(" << task.M << ", " << task.D << ")";
    return os;
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	priority_queue<int> myPriorityQueue;
	
	int n;
	cin >> n;
	
	vector<Task> taskList;
	int maxDay = -1;
	
	for(int i = 0; i < n; i++){
		int m, d;
		cin >> m >> d;	
		if(maxDay < d) maxDay = d;
		Task task(m, d);
		taskList.push_back(task);
	}
	
	int totalIncome = 0; 
	sort(taskList.begin(), taskList.end(), lateDayFirstOrder);
	
	 /* Print path vector to console */
	// copy(taskList.begin(), taskList.end(), ostream_iterator<Task>(cout, "\n"));
	// cout << "\n";
	
	int pos = 0;
	for(int day = maxDay; day >= 1; day--){
		
		// possible task at current day
		while(pos < n && taskList[pos].D >= day){
			myPriorityQueue.push(taskList[pos].M);
			pos++;
		}
		
		if(!myPriorityQueue.empty()){
			totalIncome += myPriorityQueue.top();
			myPriorityQueue.pop();	
		}
	}

	cout << totalIncome;
	
	return 0;
}
