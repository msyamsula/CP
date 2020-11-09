from datetime import datetime

def changeTimestamp(string):
    subpart = string.split(' ')
    year = int(subpart[3])
    month_verbose = {'Jan': 1, 'Feb': 2, 'Mar': 3, 'Apr': 4, 'May': 5, 'Jun': 6, 'Jul': 7, 'Aug': 8, 'Sep': 9, 'Oct': 10, 'Nov': 11, 'Dec': 12}
    month = month_verbose[subpart[2]]
    day = int(subpart[1])
    hour = int(subpart[4][:2])
    minute = int(subpart[4][3:5])
    second = int(subpart[4][6:8])

    hour_zone = int(subpart[5][1:3])
    minute_zone = int(subpart[5][3:5])
    sign = (subpart[5][:1])

    date = datetime(year=year, month=month, day=day, hour=hour, minute=minute, second=second)
    date_timestamp = datetime.timestamp(date)
    
    elapse_time_zone = float((hour_zone*3600)+(minute_zone*60))

    if sign == '-':
        utc_timestamp = date_timestamp + elapse_time_zone
    else:
        utc_timestamp = date_timestamp - elapse_time_zone

    return int(utc_timestamp)

string1 = 'Sat 02 May 2015 19:54:36 +0530'
string2 = 'Fri 01 May 2015 13:54:36 -0000'


time1 = changeTimestamp(string1)
time2 = changeTimestamp(string2)

return abs(time2 - time1)
