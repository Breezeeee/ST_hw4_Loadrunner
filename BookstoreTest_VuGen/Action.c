Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_header("DNT", 
		"1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_start_transaction("S01_T01_HomePage");

/*Correlation comment - Do not change!  Original value='48F6841C57BBEDEB5513B5B1D3E8067C' Name ='sessionID' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=sessionID",
		"RegExp=JSESSIONID=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/check_session*",
		LAST);

	web_url("101.200.120.41:12333", 
		"URL=http://101.200.120.41:12333/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://adu.g-fox.cn/adu.gif?channelid=stub.firefox.com.cn&fxversion=67.0.1&ceversion=2019.5&ver=2_2&pk=%7B3cb3755e-57ca-40f3-b991-89fc78f0b519%7D&uk=%7Bc4f76ad7-cf4f-4d87-905a-e32fa1f6c70c%7D&cehome=true&locale=zh-CN&age=4&default=false&defaultHttp=false&flash=&tracking=2&now=1560159930064", "Referer=", ENDITEM, 
		"Url=/login/check_session", ENDITEM, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		"Url=/static/media/csapp.353e1ee5.png", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_end_transaction("S01_T01_HomePage", LR_AUTO);

	lr_think_time(6);

	lr_start_transaction("S01_T02_LogIn");

	web_submit_data("check",
		"Action=http://101.200.120.41:12333/login/check",
		"Method=POST",
		"RecContentType=text/plain",
		"Referer=http://101.200.120.41:12333/login",
		"Snapshot=t19.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=usn", "Value={username}", ENDITEM,
		"Name=psw", "Value=1111aaaa", ENDITEM,
		EXTRARES,
		"URL=check_session", "Referer=http://101.200.120.41:12333/booklist", ENDITEM,
		LAST);

	lr_end_transaction("S01_T02_LogIn", LR_AUTO);

	lr_start_transaction("S01_T03_BookList");

	web_custom_request("getBook", 
		"URL=http://101.200.120.41:12333/getBook", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/booklist", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=", 
		EXTRARES, 
		"Url=/login/check_session", "Referer=http://101.200.120.41:12333/purchase", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T03_BookList", LR_AUTO);

	lr_start_transaction("S01_T04_OneBookInfo");

	web_custom_request("getBook_2", 
		"URL=http://101.200.120.41:12333/getBook", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/purchase", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_submit_data("get_comment", 
		"Action=http://101.200.120.41:12333/purchase/get_comment", 
		"Method=POST", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/purchase", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=bookID", "Value=1", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T04_OneBookInfo", LR_AUTO);

	lr_start_transaction("S01_T05_AddToCart");

	web_submit_data("add_to_cart", 
		"Action=http://101.200.120.41:12333/purchase/add_to_cart", 
		"Method=POST", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/purchase", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=book_id", "Value=1", ENDITEM, 
		EXTRARES, 
		"Url=../login/check_session", "Referer=http://101.200.120.41:12333/booklist", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T05_AddToCart", LR_AUTO);

	lr_start_transaction("S01_T06_BookList");

	web_custom_request("getBook_3", 
		"URL=http://101.200.120.41:12333/getBook", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/booklist", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=", 
		EXTRARES, 
		"Url=/login/check_session", "Referer=http://101.200.120.41:12333/purchase", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T06_BookList", LR_AUTO);

	lr_start_transaction("S01_T07_AnotherBookInfo");

	web_custom_request("getBook_4", 
		"URL=http://101.200.120.41:12333/getBook", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/purchase", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_submit_data("get_comment_2", 
		"Action=http://101.200.120.41:12333/purchase/get_comment", 
		"Method=POST", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/purchase", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=bookID", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T07_AnotherBookInfo", LR_AUTO);

	lr_start_transaction("S01_T08_AddToCart");

	web_submit_data("add_to_cart_2", 
		"Action=http://101.200.120.41:12333/purchase/add_to_cart", 
		"Method=POST", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/purchase", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=book_id", "Value=3", ENDITEM, 
		EXTRARES, 
		"Url=../login/check_session", "Referer=http://101.200.120.41:12333/cart", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T08_AddToCart", LR_AUTO);

	lr_start_transaction("S01_T09_Cart");

	web_custom_request("fetch_cart", 
		"URL=http://101.200.120.41:12333/purchase/fetch_cart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/cart", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	lr_end_transaction("S01_T09_Cart", LR_AUTO);

	lr_start_transaction("S01_T10_CreateIndent");

	web_custom_request("create_indent", 
		"URL=http://101.200.120.41:12333/purchase/create_indent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/cart", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=", 
		EXTRARES, 
		"Url=../login/check_session", "Referer=http://101.200.120.41:12333/indents", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T10_CreateIndent", LR_AUTO);

	lr_start_transaction("S01_T11_FetchIndents");

	web_submit_data("fetch_indents", 
		"Action=http://101.200.120.41:12333/fetch_indents", 
		"Method=POST", 
		"RecContentType=text/plain", 
		"Referer=http://101.200.120.41:12333/indents", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=book_filter", "Value=", ENDITEM, 
		"Name=author_filter", "Value=", ENDITEM, 
		"Name=time_filter", "Value=", ENDITEM, 
		EXTRARES, 
		"Url=/login/check_session", "Referer=http://101.200.120.41:12333/profile", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T11_FetchIndents", LR_AUTO);

	lr_start_transaction("S01_T12_UserInfo");

	web_submit_data("getinfo",
		"Action=http://101.200.120.41:12333/profile/getinfo",
		"Method=POST",
		"RecContentType=text/plain",
		"Referer=http://101.200.120.41:12333/profile",
		"Snapshot=t31.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=sessionID", "Value={sessionID}", ENDITEM,
		LAST);

	lr_end_transaction("S01_T12_UserInfo", LR_AUTO);

	lr_start_transaction("S01_T13_LogOut");

	web_url("logout", 
		"URL=http://101.200.120.41:12333/login/logout", 
		"Resource=0", 
		"Referer=http://101.200.120.41:12333/profile", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("S01_T13_LogOut", LR_AUTO);

	return 0;
}