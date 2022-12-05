#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
#include <algorithm>
#include <string>

using namespace std;

namespace sdds {
	LineManager::LineManager(const string& file, const vector<Workstation*>& stations) {
		if (file.empty())
			throw std::string("ERROR: File is empty.");
		std::ifstream filein(file);
		if (!filein)
			throw std::string("Unable to open [" + file + "].");
		std::string line;
		while (std::getline(filein, line))
		{
			std::string workstation = line.substr(0, line.find_first_of('|'));
			std::string nextWorkstation = line.erase(0, workstation.size() + 1);
			auto ws = std::find_if(stations.begin(), stations.end(), [&](Workstation* ws1) {
					return ws1->getItemName() == workstation;
				});
			m_activeLine.push_back(*ws);		
			if (!nextWorkstation.empty()) {
				for_each(stations.begin(), stations.end(), [&](Workstation* ws1) {
						if (ws1->getItemName() == nextWorkstation)
							m_activeLine.back()->setNextStation(ws1);
					});
			}
			else 
				m_activeLine.back()->setNextStation(nullptr);
			
		}
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
				auto first = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws1) {
						return ws == ws1->getNextStation();
					});
				if (first == m_activeLine.end()) 
					m_firstStation = ws;
				
			});
		m_cntCustomerOrder = g_pending.size();
	}

	void LineManager::reorderStations() {
		vector<Workstation*> new_stations;
		Workstation* last_Station = nullptr;
		unsigned int count = 0;
		while (count < m_activeLine.size()) {
			for (unsigned int i = 0; i < m_activeLine.size(); i++) {
				if (m_activeLine[i]->getNextStation() == last_Station) {
					new_stations.push_back(m_activeLine[i]);
					last_Station = m_activeLine[i];
					count++;
					break;
				}
			}
		}
		reverse(new_stations.begin(), new_stations.end());
		m_firstStation = new_stations[0];
		m_activeLine = new_stations;
	}

	bool LineManager::run(ostream& os) {
		static int count = 0;
		count++;
		os << "Line Manager Iteration: " << count << "\n";

		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}
		for (unsigned int i = 0; i < m_activeLine.size(); i++)
			m_activeLine[i]->fill(os);
		for (unsigned int i = 0; i < m_activeLine.size(); i++)
			m_activeLine[i]->attemptToMoveOrder();
		for (unsigned int i = 0; i < m_activeLine.size(); i++)
		{
			if (!m_activeLine[i]->empty()) 
				return false;
			
		}
		return true;
	}

	void LineManager::display(ostream& os) const {
		for (unsigned int i = 0; i < m_activeLine.size(); i++) 
			m_activeLine[i]->display(os);
		
	}

}