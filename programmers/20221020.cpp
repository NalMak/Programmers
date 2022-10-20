#include <string>
#include <vector>
#include <map>

using namespace std;

struct UserReport
{
	map<string,int> stmReported;
};

void GetReportDetail(const string& reportInfo, string& reportIn, string& reportOut)
{
	int spaceIdx = reportInfo.find(' ');

	reportIn = reportInfo.substr(0, spaceIdx);
	reportOut = reportInfo.substr(spaceIdx + 1, reportInfo.size());

}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {

	vector<int> answer;

	map<string,UserReport*> userReports;
	map<string, int> cacheUserData;
	vector<int> userIndexs;
	int index = 0;

	for (const auto& id : id_list)
	{
		cacheUserData[id] = index;
		++index;
	}

	map<string, int> userReportSuccess;
	answer.assign(id_list.size(),0);

	for (const auto& reportInfo : report)
	{
		string reportIn;
		string reportOut;

		GetReportDetail(reportInfo, reportOut, reportIn);

		UserReport* pReport = userReports[reportIn];
		if (pReport == nullptr)
		{
			pReport = new UserReport;
			userReports[reportIn] = pReport;
		}
		pReport->stmReported[reportOut] = 1;
	}
	
	for (const auto& userReport : userReports)
	{
		if (userReport.second->stmReported.size() >= k)
		{
			for(const auto& reporter : userReport.second->stmReported)
			{
				userReportSuccess[reporter.first]++;
			}
		}
	}

	for (const auto& success : userReportSuccess)
	{
		answer[cacheUserData[success.first]] = success.second;
	}

	return answer;
}

void main()
{
	vector<string> a;
	vector<string> b;
	a.emplace_back("muzi");
	a.emplace_back("frodo");
	a.emplace_back("apeach");
	a.emplace_back("neo");

	b.emplace_back("muzi frodo");
	b.emplace_back("apeach frodo");
	b.emplace_back("frodo neo");
	b.emplace_back("muzi neo");
	b.emplace_back("apeach muzi");


	solution(a, b, 2);
}