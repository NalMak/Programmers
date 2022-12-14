#include <string>
#include <vector>
#include <map>

using namespace std;

typedef string ReportUserID;

struct UserReport
{
	typedef int ReportedCount;

	map<ReportUserID, ReportedCount> stmReported;
};

void GetReportDetail(const string& reportInfo, string& reportIn, string& reportOut)
{
	int spaceIdx = reportInfo.find(' ');

	reportIn = reportInfo.substr(0, spaceIdx);
	reportOut = reportInfo.substr(spaceIdx + 1, reportInfo.size());
}

bool IsReported(int reportedNum, int conditionNum)
{
	return reportedNum >= conditionNum;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {


	vector<int> answer;
	answer.assign(id_list.size(),0);

	map<string,UserReport> userReports;
	map<string, int> cacheUserData;

	int index = 0;
	for (const auto& id : id_list)
	{
		cacheUserData[id] = index;
		++index;
	}

	for (const auto& reportInfo : report)
	{
		string reportTo;
		string reportFrom;

		GetReportDetail(reportInfo, reportTo, reportFrom);

		userReports[reportFrom].stmReported[reportTo] += 1;
	}
	

	typedef int ReportSuccessCount;
	map<ReportUserID, ReportSuccessCount> userReportSuccess;

	for (const auto& userReport : userReports)
	{
		if (IsReported(userReport.second.stmReported.size(), k))
		{
			for (const auto& reporter : userReport.second.stmReported)
			{
				userReportSuccess[reporter.first] += 1;
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