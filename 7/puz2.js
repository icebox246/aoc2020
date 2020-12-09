const fs = require('fs');

const lines = fs.readFileSync("./in1").toString().split('\n');

const graph = {};

function parseColorName(segment) {
	const words = segment.split(' ');
	let count=words[words.length - 3];
	if(words[words.length - 1] == "other") count = 0;
	return { count:parseInt(count), name: words[words.length - 2] + '_'  + words[words.length-1]};
}

function parseLine(line) {
	const segments = line.split(' bag');

	const parentName = parseColorName(segments[0]).name;
	if(!graph[parentName]) {
		graph[parentName] = {};
		graph[parentName].visited = false;
		graph[parentName].children = [];
	}
	for(let i = 1; i < segments.length - 1; i++) {
		const {count, name} = parseColorName(segments[i]);
		if(!graph[name]) {
			graph[name] = {};
			graph[name].visited = false;
			graph[name].children = [];
		}
		graph[parentName].children.push({count, name});
	}
}

lines.forEach(line=>parseLine(line));

let total = -1;

function DFS(node) {
	// if(node.visited===true) return 0;
	let temp = 0; 
	node.visited = true;
	// console.log(node.children)
	node.children.forEach(p=>{
		temp += p.count + p.count * DFS(graph[p.name]);
		// console.log(temp);
	});
	return temp;
}

total = DFS(graph["shiny_gold"]);
// console.log(graph["shiny_gold"]);

console.log(total);
