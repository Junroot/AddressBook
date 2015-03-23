#ifndef __SMS_H__
#define __SMS_H__

#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "AddressBook.h"


class in_sms
{
public:
	in_sms();
	in_sms(std::string content, std::string sender, std::string time);
	~in_sms();

	const std::string get_content() const;
	const std::string get_sender() const;
	const std::string get_time() const;

	void set_constent(const std::string& content);
	void set_sender(const std::string& sender);
	void set_time(const std::string& time);

private:
	std::string content;
	std::string sender;
	std::string receive_time;
	
};

class out_sms
{
public:
	out_sms();
	out_sms(std::string content, std::string receiver, std::string time);
	~out_sms();

	const std::string get_content() const;
	const std::string get_receiver() const;
	const std::string get_time() const;

	void set_constent(const std::string& content);
	void set_receiver(const std::string& receiver);
	void set_time(const std::string& time);
private:
	std::string content;
	std::string receiver;
	std::string send_time;

};

class SMS
{
public:
	SMS();
	~SMS();

	bool read_inboxfile();
	bool read_outboxfile();
	bool write_inboxfile();
	bool write_outboxfile();

	void print_inboxlists(AddressBook book,int inp);
	void print_outboxlists(AddressBook book,int inp);
	void print_insms(AddressBook book, int inp);
	void print_outsms(AddressBook book, int inp);
	
	int inSize() { return inbox.size(); }
	int outSize() { return outbox.size(); }

private:
	std::map<std::string,in_sms> inbox;
	std::map<std::string,out_sms> outbox;
};



#endif