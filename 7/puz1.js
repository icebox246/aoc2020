const fs = require('fs');

const lines = fs.readFileSync("./in1").toString().split('\n');

const graph = {};

function parseColorName(segment) {
	const words = segment.split(' ');
	return words[words.length - 2] + '_'  + words[words.length-1];
}

function parseLine(line) {
	const segments = line.split(' bag');

	const parentName = parseColorName(segments[0]);
	if(!graph[parentName]) {
		graph[parentName] = {};
		graph[parentName].visited = false;
		graph[parentName].parents = [];
	}
	for(let i = 1; i < segments.length - 1; i++) {
		const childName = parseColorName(segments[i]);
		if(!graph[childName]) {
			graph[childName] = {};
			graph[childName].visited = false;
			graph[childName].parents = [];
		}
		graph[childName].parents.push(parentName);
	}
}

lines.forEach(line=>parseLine(line));

let total = -1;

function DFS(node) {
	if(node.visited===true) return;
	node.visited = true;
	total++;
	// console.log(node.parents);
	node.parents.forEach(p=>DFS(graph[p]));
}

DFS(graph["shiny_gold"]);

console.log(total);
