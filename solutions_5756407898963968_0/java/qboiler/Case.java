/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.brycealcock.codejam;

/**
 *
 * @author bryce
 */
abstract public class Case {
    
    private final int caseNumber;
    
    protected Case(int number){
        caseNumber = number;
    }
    
    
    @Override
    final public String toString(){
        return "Case #"+caseNumber+": "+ caseResult();
    }
    
    abstract protected String caseResult();
    abstract protected Case processCase();
}
