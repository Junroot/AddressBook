#include <Windows.h>
#include "sms.h"
#include "AddressBook.h"

using namespace std;

void setscolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

SMS::SMS()
{
	read_inboxfile();
	read_outboxfile();
}
SMS::~SMS(){}

/**	파일 입출력에 관해서
	inbox파일과 outbox파일 공통
	보낸시각/받은시각을 년월일시분초YYMMDDhhmmss형식의 12자리로 받음
	보낸번호 string으로 받음
	Getline을 이용해서 한 줄은 문자 내용으로 받음
	-문자 내용에 개행 불가
*/

bool SMS::read_inboxfile()
{
	ifstream inbox_file("SMSinbox.txt", ios::in);
	string number;
	string time;
	string content;
	while (inbox_file >> time >> number)
	{
		if (time.size() != 12)
		{
			return false;
		}
		getline(inbox_file,content);
		getline(inbox_file, content);
		in_sms new_in_sms(content, number, time);
		inbox.insert(make_pair(time, new_in_sms));
	}
	inbox_file.close();
	return true;
}
bool SMS::read_outboxfile()
{
	ifstream outbox_file("SMSoutbox.txt", ios::in);
	string number;
	string time;
	string content;
	while (outbox_file >> time >> number)
	{
		if (time.size() != 12)
		{
			return false;
		}
		getline(outbox_file, content);
		getline(outbox_file, content);
		out_sms new_out_sms(content, number, time);
		outbox.insert(make_pair(time, new_out_sms));
		
	}
	outbox_file.close();
	return true;
}

/**	TODO
*	날짜(년/월/일)
*	시각(시:분:초)
*	위의 두 개 출력 이후 번호로 addressbook search
*	서치한 결과가 있으면 저장된 이름으로 출력
*	없으면 그냥 번호로 출력
*/
void SMS::print_inboxlists(AddressBook book,int inp)
{
	int i = 1;
	for (map<string, in_sms>::reverse_iterator it = inbox.rbegin();
		it != inbox.rend(); it++)
	{
		cout << "\t";
		if (i == inp) cout << "▶";
		string str = it->first;
		cout << "20" << str[0] << str[1] << "-";
		cout << str[2] << str[3] << "-";
		cout << str[4] << str[5] << "  ";
		cout << str[6] << str[7] << ":";
		cout << str[8] << str[9] << "  ";
		if (book.SearchName(it->second.get_sender()) != "")
		{
			printf("%-15s", book.SearchName(it->second.get_sender()).c_str());
		}
		else
		{
			printf("%-15s", it->second.get_sender().c_str());
		}
		setscolor(8, 0);
		if (it->second.get_content().size() <= 16)
		{
			cout << it->second.get_content() << endl;
		}
		else
		{
			for (int i = 0; i <= 12; i++)
			{
				cout << it->second.get_content()[i];
			}
			cout << "..." << endl;
		}
		setscolor(15, 0);
		i++;
	}
}
void SMS::print_outboxlists(AddressBook book, int inp)
{
	int i = 1;
	for (map<string, out_sms>::reverse_iterator it = outbox.rbegin();
		it != outbox.rend(); it++)
	{
		cout << "\t";
		if (i == inp) cout << "▶";
		string str = it->first;
		cout << "20" << str[0] << str[1] << "-";
		cout << str[2] << str[3] << "-";
		cout << str[4] << str[5] << "  ";
		cout << str[6] << str[7] << ":";
		cout << str[8] << str[9] << "  ";
		if (book.SearchName(it->second.get_receiver()) != "")
		{
			printf("%-15s", book.SearchName(it->second.get_receiver()).c_str());
		}
		else
		{
			printf("%-15s", it->second.get_receiver().c_str());
		}
		setscolor(8, 0);
		if (it->second.get_content().size() <= 16)
		{
			cout << it->second.get_content() << endl;
		}
		else
		{
			for (int i = 0; i <= 16; i++)
			{
				cout << it->second.get_content()[i];
			}
			cout << "..." << endl;
		}
		setscolor(15, 0);
		i++;
	}
}



in_sms::in_sms(){}
in_sms::in_sms(std::string c, std::string s, std::string t):
	content(c), sender(s), receive_time(t){}
in_sms::~in_sms(){}

const string in_sms::get_content() const { return content; }
const string in_sms::get_sender() const{ return sender; }
const string in_sms::get_time() const{ return receive_time; }

void in_sms::set_constent(const string& c){ content = c; }
void in_sms::set_sender(const string& s){ sender = s; }
void in_sms::set_time(const string& t){ receive_time = t; }


out_sms::out_sms(){}
out_sms::out_sms(std::string c, std::string r, std::string t):
	content(c), receiver(r), send_time(t){}
out_sms::~out_sms(){}

const string out_sms::get_content() const{ return content; }
const string out_sms::get_receiver() const{ return receiver; }
const string out_sms::get_time() const{ return send_time; }

void out_sms::set_constent(const string& c){ content = c; }
void out_sms::set_receiver(const string& r){ receiver = r; }
void out_sms::set_time(const string& t){ send_time = t; }


void SMS::print_insms(AddressBook book, int inp)
{
	int i = 1;
	for (map<string, in_sms>::reverse_iterator it = inbox.rbegin();
		it != inbox.rend(); it++)
	{
		if (i == inp)
		{
			cout << "sender: ";
			if (book.SearchName(it->second.get_sender()) != "")
			{
				cout << book.SearchName(it->second.get_sender()) << endl;
			}
			else
			{
				cout << it->second.get_sender() << endl;
			}
			cout << it->second.get_content();
			return;
		}
		i++;
	}
}

void SMS::print_outsms(AddressBook book, int inp)
{
	int i = 1;
	for (map<string, out_sms>::reverse_iterator it = outbox.rbegin();
		it != outbox.rend(); it++)
	{
		if (i == inp)
		{
			cout << "sender: ";
			if (book.SearchName(it->second.get_receiver()) != "")
			{
				cout << book.SearchName(it->second.get_receiver()) << endl;
			}
			else
			{
				cout << it->second.get_receiver() << endl;
			}
			cout << it->second.get_content();
			return;
		}
		i++;
	}
}