#!/usr/bin/env python


import math


def baseSequence( inputStr ):
	sequence = ""
	currentChar = None
	for char in inputStr:
		if char != currentChar:
			sequence += char
			currentChar = char
	return sequence


def hasCommonBase( stringList ):
	base = None
	for string in stringList:
		if base:
			if baseSequence( string ) != base:
				return False
		else:
			base = baseSequence( string )
	return True


def countedSequence( inputStr ):
	sequence = []
	currentChar = None
	currentCount = 0
	for char in inputStr:
		if char != currentChar:
			if currentCount > 0:
				sequence.append( ( currentChar, currentCount ) )
			currentChar = char
			currentCount = 1
		else:
			currentCount += 1
	sequence.append( ( currentChar, currentCount ) )
	return sequence


def averagedSequence( sequenceList ):
	numSeq = len( sequenceList )
	accSeq = [ x for x in sequenceList[ 0 ] ]
	numItems = len( accSeq )
	for seqIdx in range( 1, numSeq ):
		for itemIdx in range( 0, numItems ):
			accChar = accSeq[ itemIdx ][ 0 ]
			accCount = accSeq[ itemIdx ][ 1 ]
			curCount = sequenceList[ seqIdx ][ itemIdx ][ 1 ]
			accSeq[ itemIdx ] = ( accChar, accCount + curCount )
	for itemIdx in range( 0, numItems ):
		accChar = accSeq[ itemIdx ][ 0 ]
		accCount = accSeq[ itemIdx ][ 1 ]
		average = float( accCount ) / float( numSeq )
		if average - math.floor( average ) < 0.5:
			average = int( math.floor( average ) )
		else:
			average = int( math.floor( average ) ) + 1
		accSeq[ itemIdx ] = ( accChar, average )
	return accSeq


if __name__ == "__main__":
	T = int( raw_input() )
	for case in range( 0, T ):
		N = int( raw_input() )
		strings = []
		for _ in range( 0, N ):
			strings.append( raw_input().strip() )
		if hasCommonBase( strings ):
			sequences = []
			for string in strings:
				sequences.append( countedSequence( string ) )
			aveSeq = averagedSequence( sequences )
			moves = 0
			numItems = len( aveSeq )
			for seq in sequences:
				for itemIdx in range( 0, numItems ):
					moves += abs( seq[ itemIdx ][ 1 ] - aveSeq[ itemIdx ][ 1 ] )
			print "Case #%d: %d" % ( case + 1, moves )
		else:
			print "Case #%d: Fegla Won" % ( case + 1 )
