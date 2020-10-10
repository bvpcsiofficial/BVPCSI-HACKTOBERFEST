class binarytree:
	def __init__(self,data):
		self.data=data
		self.left=None
		self.right=None

def binaryinput():
	rootdata=int(input())
	if rootdata==-1:
		return None
	root=binarytree(rootdata)
	leftt=binaryinput()
	rightt=binaryinput()
	root.left=leftt
	root.right=rightt
	return root

def printt(root):
	if root==None:
		return
	print()
	print(root.data,end=":")
	if root.left!=None:
		print('L',root.left.data,end=",")
	if root.right!=None:
		print('R',root.right.data,end="")
	printt(root.left)
	printt(root.right)
	
	return root

def removeleaf(root):
	if root==None:
		return
	if root.left==None and root.right==None:
		

x=binaryinput()
printt(x)