#include "sms.h"
#include "AddressBook.h"

using namespace std;

SMS::SMS()
{
	read_inboxfile();
	read_outboxfile();
}
SMS::~SMS()
{
	write_inboxfile();
	write_outboxfile();
}

/**	파일 입출력에 관해서
	inbox파일과 outbox파일 공통
	보낸시각/받은시각을 년월일시분초YYMMDDhhmmss형식의 12자리로 받음
	보낸번호 string으로 받음
	내용을 ""안에 써 넣게 함
		-> 현재 문제점: 내용 중간에 "가 나오면 그 전까지로 인식하고 끝남
*/

bool SMS::read_inboxfile()
{
	ifstream inbox_file("SMSinbox.txt", ios::in);
	string number;
	string time;
	string content;
	char ch;
	while (inbox_file >> time >> number)
	{
		if (time.size() != 12)
		{
			return false;
		}
		inbox_file.get(ch);
		if (ch != '"')
		{
			return false;
		}
		while (ch = inbox_file.get() != '"')
		{
			content.push_back(ch);
		}
		in_sms new_in_sms(content, number, time);
		inbox.push_back(new_in_sms);
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
	char ch;
	while (outbox_file >> time >> number)
	{
		if (time.size() != 12)
		{
			return false;
		}
		outbox_file.get(ch);
		if (ch != '"')
		{
			return false;
		}
		while (ch = outbox_file.get() != '"')
		{
			content.push_back(ch);
		}
		out_sms new_out_sms(content, number, time);
		outbox.push_back(new_out_sms);
		
	}
	outbox_file.close();
	return true;
}

bool SMS::write_inboxfile()
{
	ofstream inbox_file("SMSinbox.txt", ios::out);
	for (vector<in_sms>::iterator it = inbox.begin();
		it != inbox.begin(); it++)
	{
		inbox_file << it->get_time() << endl;
		inbox_file << it->get_sender() << endl;
		inbox_file << '"' << it->get_content() << '"' << endl;
	}
	inbox_file.close();
	return true;
}
bool SMS::write_outboxfile()
{
	ofstream outbox_file("SMSi=\outnbox.txt", ios::out);
	for (vector<out_sms>::iterator it = outbox.begin();
		it != outbox.begin(); it++)
	{
		outbox_file << it->get_time() << endl;
		outbox_file << it->get_receiver() << endl;
		outbox_file << '"' << it->get_content() << '"' << endl;
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
void SMS::print_inboxlists()
{
	for (int i = 0; i < inbox.size(); i++)
	{
		
	}
}
void SMS::print_outboxlists(){}


/** TODO
*	온 시각 순서대로 sort하기
*	sms.h에서 include한 algorithm에 있는 sort이용
*		->시각을 비교하는 함수를 만들어야함
*/
void SMS::sort_inbox(){}
void SMS::sort_outbox(){}


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
