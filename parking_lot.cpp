#include<iostream>
#include<string>
#include <fstream>
using namespace std;

int counter = 1;

class slot {
public:
	int slotnum;
	string regnum;
	string color;
	slot()
	{
		//cout << "Created " << counter << " Slot" << endl;
		slotnum = counter;
		counter++;
		regnum = "NONE";
		color = "NONE";
	}
};

class plot {
public:
	slot * s;
	int p_size;
	plot(int n) {
		p_size = n;
		s = new slot[n];
                cout<<"Created a parking lot with "<<n<<" slots"<<endl;
	}

	void p_park(string reg_num, string car_color) {
		int flag = 1;
		for (int i = 0; i < p_size; i++)
		{
			if (s[i].regnum == "NONE")
			{
				flag = 0;
				s[i].regnum = reg_num;
				s[i].color = car_color;
				cout << "Allocated slot number: " << s[i].slotnum << endl;
				break;
			}
		}
		if (flag == 1) {
			cout << "Sorry, parking lot is full" << endl;
		}
	}

	void p_leave(int slot_num) {
		if (s[slot_num - 1].regnum != "NONE")
		{
			s[slot_num - 1].regnum = "NONE";
			s[slot_num - 1].color = "NONE";
			cout << "Slot number " << slot_num << " is free" << endl;
		}
		else
		{
			cout << "Slot number " << slot_num << " is free" << endl;
		}
	}

	void p_status() {
		cout << "Slot No.  Registration No  Colour" << endl;
		for (int i = 0; i < p_size; i++) {
			if (s[i].regnum != "NONE")
				cout << s[i].slotnum << "  " << s[i].regnum << "  " << s[i].color << endl;
		}
	}

	void reg_nums_color(string query_color) {
		string res = "";
		for (int i = 0; i < p_size; i++) {
			if (s[i].color == query_color)
				res += s[i].regnum + ", ";
		}
		res.pop_back();
		res.pop_back();
		cout << res << endl;
	}

	void slot_nums_color(string query_color) {
		string res = "";
		for (int i = 0; i < p_size; i++) {
			if (s[i].color == query_color)
				res += to_string(s[i].slotnum) + ", ";
		}
		res.pop_back();
		res.pop_back();
		cout << res << endl;
	}

	void slot_num_reg(string query_reg) {
		string res = "Not found";
		for (int i = 0; i < p_size; i++) {
			if (s[i].regnum == query_reg)
			{
				res = to_string(s[i].slotnum);
				break;
			}
		}
		cout << res << endl;
	}
};

int main(int argc, char* argv[]) {
	int pos, pos2;
	string query;
	string query_key1, query_key2, query_key3, query_key;
        if(argc==2)
        {
          ifstream file(argv[1]);
          string str;
          getline(file,str);
          query=str;
          pos = query.find(' ', 0);
          query_key = query.substr(pos + 1);
	  query_key1 = query.substr(0, pos);
          plot p(stoi(query_key));
          while(getline(file,str))
          {
                        query=str;
                        pos = query.find(' ', 0);
			query_key = query.substr(pos + 1);
			query_key1 = query.substr(0, pos);
			pos2 = query_key.find(' ', 0);
			query_key3 = query_key.substr(pos2 + 1);
			query_key2 = query_key.substr(0, pos2);
			if (query_key1 == "park") {
				p.p_park(query_key2, query_key3);
			}
			else if (query_key1 == "leave") {
				p.p_leave(stoi(query_key2));
			}
			else if (query_key1 == "status") {
				p.p_status();
			}
			else if (query_key1 == "registration_numbers_for_cars_with_colour") {
				p.reg_nums_color(query_key2);
			}
			else if (query_key1 == "slot_numbers_for_cars_with_colour") {
				p.slot_nums_color(query_key2);
			}
			else if (query_key1 == "slot_number_for_registration_number") {
				p.slot_num_reg(query_key2);
			}else{}

          }
        }else
       { 
	do
	{
		getline(cin, query);
		pos = query.find(' ', 0);
		query_key = query.substr(pos + 1);
		query_key1 = query.substr(0, pos);
	} while (query_key1 != "create_parking_lot");
	plot p(stoi(query_key));
	int flag = 1;
		while (flag != 0) {
			getline(cin, query);
			pos = query.find(' ', 0);
			query_key = query.substr(pos + 1);
			query_key1 = query.substr(0, pos);
			pos2 = query_key.find(' ', 0);
			query_key3 = query_key.substr(pos2 + 1);
			query_key2 = query_key.substr(0, pos2);
			if (query_key1 == "park") {
				p.p_park(query_key2, query_key3);
			}
			else if (query_key1 == "leave") {
				p.p_leave(stoi(query_key2));
			}
			else if (query_key1 == "status") {
				p.p_status();
			}
			else if (query_key1 == "registration_numbers_for_cars_with_colour") {
				p.reg_nums_color(query_key2);
			}
			else if (query_key1 == "slot_numbers_for_cars_with_colour") {
				p.slot_nums_color(query_key2);
			}
			else if (query_key1 == "slot_number_for_registration_number") {
				p.slot_num_reg(query_key2);
			}
			if (query == "abort") {
				flag = 0;
			}
		}
        }
		return 0;
}
