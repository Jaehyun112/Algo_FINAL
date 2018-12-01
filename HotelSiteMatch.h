#pragma once

#include"Graph.h"

typedef struct HOTEL_SITE_MATCH *hotel_site_ptr;
typedef struct HOTEL_SITE_MATCH {
	int CityNum;      //HS_SATIS에서 채울부분, 도시 이름
	int Preference;		//평점
	int Hotel;         //HS_SATIS에서 채울부분, 호텔 이름
	int Satisfaction;   //HS_SATIS에서 채울부분, 만족도
	int Price;          //HS_SATIS에서 채울부분, 호텔 가격
	int Day;         //HS_DAY 묵는 날
	int Budget;         //HS_DAY, 그도시에서 묵고나서 떠나기 전까지 남은돈
	hotel_site_ptr next;
}HotelSite;

hotel_site_ptr HS_MATCH(node_ptr node, graph_ptr gp, int budget, int period);
hotel_site_ptr HS_SATISFACTION(node_ptr node, graph_ptr gp);
hotel_site_ptr HS_DAY(hotel_site_ptr head, int period, int sitenum);
HT_RBnode_ptr HotelMatch(HT_RBnode_ptr root, int budget);