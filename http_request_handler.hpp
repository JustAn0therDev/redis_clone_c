#include "httplib.h"
#include "black_marlin.hpp"

#ifndef HTTPREQUESTHANDLERCPP
#define HTTPREQUESTHANDLERCPP
class HttpRequestHandler {
public:
	// The program's address.
	const char* m_ip_address = "127.0.0.1";
	// The program's running port.
	const int m_port = 7000;
	// Handles a Get request.
	void HandleGet(const BlackMarlin& p_blackMarlin, const httplib::Request& p_req, httplib::Response& p_res) const;
	// Handles a Post request.
	void HandlePost(BlackMarlin& p_blackMarlin, const httplib::Request& p_req, httplib::Response& p_res);
	// Handles Put and Patch requests.
	void HandlePutAndPatch(BlackMarlin& p_blackMarlin, const httplib::Request& p_req, httplib::Response& p_res);
	// Handles a Delete request.
	void HandleDelete(BlackMarlin& p_blackMarlin, const httplib::Request& p_req, httplib::Response& p_res);
	// Handles a Delete request in the "/flush" route.
	void HandleDeleteFlush(BlackMarlin& p_blackMarlin, httplib::Response& p_res);
	// Handles a Get request in the "/exists" route.
	void HandleGetExists(const BlackMarlin& p_blackMarlin, const httplib::Request& p_req, httplib::Response& p_res) const;
	// Handles a Get request in the "/count" route.
	void HandleGetCount(const BlackMarlin& p_blackMarlin, httplib::Response& p_res) const;
private:
	// Content-Type header value if needed.
	const char* m_content_type = "*/*; charset=utf-8";
	bool IsValidSecondsParam(std::string p_seconds_param);
};
#endif