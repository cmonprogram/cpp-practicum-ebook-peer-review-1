#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

class BookStat {
public:
	BookStat() {
		//Общее количество запросов не превосходит 10⁶.
		user_page.resize(100000); //номера пользователей не превосходят 10⁵
		page_user.resize(1000); //номера страниц не превосходят 1000. 
	}

	//сохранить факт того, что пользователь под номером user дочитал книгу до страницы page. Если ранее такой пользователь не встречался, нужно его добавить. Гарантируется, что в рамках одного пользователя номера страниц в соответствующих ему событиях возрастают.
	void read(int user, int page) {
		for (int i = user_page[user] + 1; i <= page; ++i) {
			++page_user[i];
		}
		user_page[user] = page;
		all_users.insert(user);
	}

	//сообщить пользователю user, какая доля существующих пользователей, не считая его самого, прочитала меньшую часть книги, чем он. 
	//Если этот пользователь на данный момент единственный, доля считается равной 1. 
	//Если для данного пользователя пока не было ни одного события READ, доля считается равной 0, а сам пользователь не учитывается при вычислении долей для других пользователей до тех пор, пока для него не случится событие READ.

	double cheer(int user) {
		if (!all_users.count(user)) return 0;
		if (all_users.size() == 1) return 1;
		double users = page_user[user_page[user]] - 1;
		double all = all_users.size() - 1;
		return 1 - (users / all);
	}

private:
	//В первом по индексу n будет храниться номер страницы, до которой дочитал пользователь id, равным n. 
	//Во втором по каждому индексу m будет храниться количество пользователей, дочитавших как минимум до страницы m.
	std::vector<int> user_page;
	std::vector<int> page_user;
	std::set<int> all_users;
};

int main() {
	BookStat obj;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string command;
		cin >> command;
		if (command == "READ") {
			int user, page;
			cin >> user >> page;
			obj.read(user, page);
		}
		if (command == "CHEER") {
			int user;
			cin >> user;
			cout << setprecision(6) << obj.cheer(user) << endl;
		}
	}
}