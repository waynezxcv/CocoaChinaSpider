# -*- coding: utf-8 -*-


import scrapy
from scrapy.selector import Selector
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.http import Request



class articleSpider(scrapy.Spider):
    name = "articleSpider"
    allowed_domains = ["cocoachina.com"]
    start_urls = [
        "http://www.cocoachina.com/industry/20151223/14773.html",
    ]

    def parse(self, response):
    	items = []
        for detailSelector in response.xpath('//div[@id="detailbody"]/p'):
			if len(detailSelector.xpath('text()')) != 0:
				items.append(detailSelector.xpath('text()').extract()[0])
			if len(detailSelector.xpath('img/@src')) != 0:
				items.append(detailSelector.xpath('img/@src').extract()[0])
	for i in range(0,len(items)):
		print "%s ........... %s" % (items[i],i)       	