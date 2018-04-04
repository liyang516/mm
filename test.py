#!/usr/bin/python
#coding=utf-8
import sys
import string
import glob
import os

# def GetFileList(dir, fileList):
# 	if os.path.isfile(dir):
# 		fileList.append(dir)
# 	elif os.path.isdir(dir):
# 		for s in os.listdir(dir):
# 			newDir = os.path.join(dir, s)
# 			GetFileList(newDir, fileList)

# 	return fileList

def GetFileList(dir, fileList):
	if os.path.isfile(dir):
		fileList.append(dir)
	elif os.path.isdir(dir):
		for x in os.listdir(dir):
			newDir = os.path.join(dir,x)
			GetFileList(newDir, fileList)
	return fileList

def fab(n):
  if n<2:
    return 1
  else:
	return fab(n-1)+fab(n-2)


class Singlet(object):
    # _instance=None
    _first_init=False
    # 类一创建就初始化（个人理解：类似java中的构造方法）,必须有返回值
    def __new__(cls,age,name):
        # if not cls._instance:
        if not hasattr(cls, "instance"):
            cls.instance=object.__new__(cls)
        return cls.instance

    # 初始化数据
    def __init__(self,age,name):
        if not self._first_init:
        # if not hasattr(self, "first_init"):
            self.age=age
            self.name=name
            Singlet._first_init=True


   

if __name__ == "__main__":
	print 'hello'
	print '你好'

	a=Singlet(26,"xiaokeke")
	b=Singlet(22,"liulili")

	print(id(a))
	print(id(b))

	print(a.name)
	print(b.name)

	# for file in GetFileList('/home/liyang/mm',[]):
	# 	print file
	# print fab(5)

	# print "this is %s %s" % ("my",'apple')
	# print "this is %(whose)s %(fruit)s" % {'whose': 'my', 'fruit': 'apple'}
	# print "this is {0} {1}".format("my",'apple')
	# print "this is {whose} {fruit}".format(whose="my",fruit='apple')

	# f = open('string_help.txt','w')
	# sys.stdout = f
	# help(string)
	# f.close()

	# temp = glob.glob('/home/liyang/mm/*.*')
	# print temp
	# print os.listdir('/home/liyang/mm')
	# print '----------------------------------------'
	# path = '/home/liyang/mm'
	# print os.path.isdir(path)
	# print os.path.exists(path)
	# print os.path.isfile(path)

	# with open('/home/liyang/mm/string_help.txt','r') as f:
	# 	print f.read()

