/*--
	Capture The Flag
	Author: Maikel
	
	Capture the flag of the opposing team and bring it to your base to gain points.
--*/


#include Library_ConfigurableGoal

public func GetDescription(int plr)
{
	var flags = GetWinScore() - score_list_points[GetPlayerTeam(plr)];
	if (IsFulfilled())
		return "$MsgGoalFulfilled$";
	else
	{
		var msg = "$MsgGoalCaptureTheFlag$";
		if (flags == 1)
			return Format("%s %s", msg, "$MsgGoalUnfulfilled1$");
		else
			return Format("%s %s", msg, Format("$MsgGoalUnfulfilledX$", flags));
	}
}

public func Activate(int byplr)
{
	var msg = GetDescription(byplr);
	
	MessageWindow(msg, byplr);
	return;
}

/**
private func EliminateOthers(int win_team)
{
	for (var i = 0; i < GetPlayerCount(); i++)
	{
		var plr = GetPlayerByIndex(i);
		var team = GetPlayerTeam(plr);
		if (team != win_team)
			EliminatePlayer(plr);	
	}
	return;
}
*/

// Returns the number of players in a specific team.
private func GetPlayerInTeamCount(int team)
{
	var cnt = 0;
	for (var i = 0; i < GetPlayerCount(); i++)
		if (GetPlayerTeam(GetPlayerByIndex(i)) == team)
			cnt++;
	return cnt;
}


local Name = "$Name$";
