import pyodbc
from time import strftime
import datetime

inputfile = open('SLSNW.N20150528')
#outputfile = open('sqltest.csv','w')
cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER=TRNAV;DATABASE=navision;Trusted_Connection=yes;')
cursor = cnxn.cursor()

inputfile.readline()

previousLine = [0,0,0,0,0,0,0]
vipArray = []
vipEntryArray = []
linesToImport = []
linesToDelete = []

for line in inputfile:
    parse = line.split(",")
    if parse[4] == previousLine[2]:
        vipArray.append([parse[25],parse[3],parse[4],parse[6],int(parse[7]),float(parse[11]),parse[15]])
    else:
        cursor.execute("""SELECT
                            [Talking Rain$VIP Chain].[Parent Chain] as store
                        FROM
                            [Talking Rain$VIP Chain]
                        LEFT JOIN [Talking Rain$VIP Outlet] on [Talking Rain$VIP Outlet].[Chain] = [Talking Rain$VIP Chain].[Chain]
                        WHERE
                            [Talking Rain$VIP Outlet].[VIPID] = ?""", str(previousLine[6]))
        row = cursor.fetchone()
        # store = row.store
        # print (store)

        if cursor.fetchone() == '82407':
            print ("\n")
            for y in cursor:
                print (y.store)

            print ("\n vipArray: \n")
            for x in vipArray:
                print (x)


            cursor.execute("""SELECT
                                [Talking Rain$VIP Entries].[Invoice No_] as Invoice,
                                [Talking Rain$VIP Entries].[Invoice Date] as idate,
                                [Talking Rain$VIP Entries].[Customer No_] as customer,
                                [Talking Rain$VIP Entries].[Item No_] as item,
                                [Talking Rain$VIP Entries].[Quantity] as quantity,
                                [Talking Rain$VIP Entries].[Net Price] as price,
                                [Talking Rain$VIP Entries].[VIPID] as store
                            FROM [Talking Rain$VIP Entries]
                            LEFT JOIN [Talking Rain$VIP Outlet] on [Talking Rain$VIP Outlet].[VIPID] = [Talking Rain$VIP Entries].[VIPID]
                            LEFT JOIN [Talking Rain$VIP Chain] on [Talking Rain$VIP Outlet].[Chain] = [Talking Rain$VIP Chain].[Chain]
                            WHERE
                                [Talking Rain$VIP Entries].[Invoice No_] = ? and
                                [Talking Rain$VIP Entries].[Customer No_] = ?""", str(previousLine[2]), str(previousLine[0]))

            for row in cursor:
                vipEntryArray.append([row.customer,strftime("%Y%m%d",row.idate.timetuple()),row.Invoice,row.item,row.quantity,float(row.price),row.store])
                # print (row.customer,strftime("%Y%m%d",row.idate.timetuple()),row.Invoice,row.item,row.quantity,float(row.price))

            print ("\n vipEntryArray: \n")

            for line in vipEntryArray:
                print (line)

            print ("\n Array Test: \n")

            print (vipArray == vipEntryArray)

            linesToImport = [line for line in vipArray if line not in vipEntryArray]
            linesToDelete = [line for line in vipEntryArray if line not in vipArray]

            print ("\n linesToImport: \n")

            for line in linesToImport:
                print (line)

            print ("\n linesToDelete: \n")

            for line in linesToDelete:
                print (line)


            print ('\n')
        vipArray = []
        vipEntryArray = []
        vipArray.append([parse[25],parse[3],parse[4],parse[6],int(parse[7]),float(parse[11]),parse[15]])
    previousLine = [parse[25],parse[3],parse[4],parse[6],int(parse[7]),float(parse[11]),parse[15]]













# cursor.execute("SELECT top 10 [Talking Rain$VIP Entries].[Invoice No_] as Invoice,[Talking Rain$VIP Entries].[Invoice Date] as date,[Talking Rain$VIP Entries].[Customer No_] as customer,[Talking Rain$VIP Entries].[Item No_] as item,[Talking Rain$VIP Entries].[Quantity] as quantity,[Talking Rain$VIP Entries].[Net Price] as price FROM [Talking Rain$VIP Entries]")
# for row in cursor:
#     vipEntryArray.append([row.customer,strftime("%Y%m%d",row.date.timetuple()),row.Invoice,row.item,row.quantity,int(row.price)])
#     print (row.customer,strftime("%Y%m%d",row.date.timetuple()),row.Invoice,row.item,row.quantity,int(row.price))
#
# print ("\n Array Test: \n")
#
# for line in vipEntryArray:
#     print (line)
#
# print (vipEntryArray == vipEntryArray)
#
#
inputfile.close()
#outputfile.close()
