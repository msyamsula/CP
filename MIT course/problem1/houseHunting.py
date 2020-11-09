import re
'''
prompting user
'''
class HouseHunting():
    def __init__(self,name):
        self.__totalMonths=0
        self.__name=name
        self.__currentSaving=0
        self.__prices=[ None for i in range(3) ]
        self.__promptingList=[
            ['Enter your starting annual salary:', 'annual salary.','\A\d+'],
            ['Enter the percent of your salary to save, as a decimal:','saving.','\A0.\d+'],
            ['Enter the cost of your dream home:', 'dream home','\A\d+'],
            # ['Enter the semi-annual raise, as a decimal:', 'semi-annual raise','\A0.\d+']
        ]

    def prompting(self,n):
        print(self.__promptingList[n][0], end=' ')
        number=input()
        numberPattern=self.__promptingList[n][2]
        check=re.findall(numberPattern,number)

        if check:
            self.__prices[n]=float(check[0])
            # print(self.__prices[n])           
            pass
        else:
            print( ('{num} isn\'t valid number for ' + self.__promptingList[n][1]).format(num=number) )
            print(self.__prices[n])
            self.prompting(n)

    def getTotalCost(self):
        return self.__prices[2]

    def getDPneeded(self):
        return self.__prices[2]*0.25

    def getCurrentSaving(self):
        return self.__currentSaving

    def saving(self,r=0.04):
        self.__currentSaving+=self.__currentSaving*r/12
        self.__currentSaving+=self.__prices[1]*(self.__prices[0]/12)

    def getPortionSaved(self):
        return self.__currentSaving/self.__prices[2]

    def calculate(self):
        while(self.__currentSaving<self.getDPneeded()):
            self.__totalMonths+=1
            self.saving()
            # print(self.__currentSaving, self.__totalMonths)


    def start(self):
        for i in range(3):
            self.prompting(i)

        self.calculate()

        print('Number of months: ', self.__totalMonths)



#testing
p1=HouseHunting('syamsul')
p1.start()
        

    