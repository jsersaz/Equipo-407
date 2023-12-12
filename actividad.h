#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <iostream>
#include <string>

class Actividad{
	private:
		int act_id_;
		std::string name_;
		std::string begin_date_;
		std::string end_date_;
		bool status_;
		std::string description_;
		float price_;
		int capacity_;
		int faculty_id_;

	public:
		Actividad(	int act_id,
					std::string name="empty",
					std::string begin_date="empty",
					std::string end_date="empty",
					bool status=false,
					std::string description="empty",
					float price=0.0,
					int capacity=0,
					int faculty_id=0) {act_id_=act_id;}
		
		int GetActId() {return act_id_;}
		std::string GetName() {return name_;}
		std::string GetBeginDate() {return begin_date_;}
		std::string GetEndDate() {return end_date_;}
		bool GetStatus() {return status_;}
		std::string GetDescription() {return description_;}
		float GetPrice() {return price_;}
		int GetCapacity() {return capacity_;}
		int GetFacultyId() {return faculty_id_;}

		void SetActId(int act_id) {act_id_=act_id;}
		void SetName(std::string name) {name_=name;}
		void SetBeginDate(std::string begin_date) {begin_date_=begin_date;}
		void SetEndDate(std::string end_date) {end_date_=end_date;}
		void SetStatus(bool status) {status_=status;}
		void SetDescription(std::string description) {description_=description;}
		void SetPrice(float price) {price_=price;}
		void SetCapacity(int capacity) {capacity_=capacity;}
		void SetFacultyId(int faculty_id) {faculty_id_=faculty_id;}
};

#endif