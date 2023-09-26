cmake_minimum_required(VERSION 3.20.0)
project(MeansTransport)

file(GLOB prjct
    *
    grount/*
    air/*
)

add_library(transport SHARED ${prjct})
