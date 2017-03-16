problem_numbers=int(raw_input())
alphabet=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
for problem_id in xrange(1,problem_numbers+1):
 party_numbers=int(raw_input())
 senators=[int(i)for i in raw_input().split(' ')]
 senators_dict={alphabet[i]:x for i,x in enumerate(senators)}
 top_two=sorted(senators_dict.iteritems(),key=lambda(k,v):(-v,k))[:2]
 senators_dict.pop(top_two[0][0],None)
 senators_dict.pop(top_two[1][0],None)
 steps_results=''
 top_two_delta=top_two[0][1]-top_two[1][1]
 steps_results+=(top_two[0][0]+top_two[0][0]+' ')*(top_two_delta/2)
 if top_two_delta%2!=0:
  steps_results+=top_two[0][0]+' '
 for senator in senators_dict:
  numbers=senators_dict[senator]
  if(numbers/2)!=0:
   steps_results+=(senator)*(numbers/2)*2+' '
  if numbers%2!=0:
   steps_results+=senator+' '
 small_of_top_two=top_two[1][1]
 for x in xrange(0,small_of_top_two):
  steps_results+=(top_two[0][0]+top_two[1][0])+' '
 print "Case #{}: {}".format(problem_id,steps_results)
# Created by pyminifier (https://github.com/liftoff/pyminifier)

