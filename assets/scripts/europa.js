var ECL=function(e){"use strict";function t(e,t){return t={exports:{}},e(t,t.exports),t.exports}function n(e){var t=void 0===e?"undefined":u(e);return!!e&&("object"==t||"function"==t)}function o(e){return!!e&&"object"==(void 0===e?"undefined":u(e))}function i(e){return"symbol"==(void 0===e?"undefined":u(e))||o(e)&&_.call(e)==v}function r(e){if("number"==typeof e)return e;if(i(e))return f;if(n(e)){var t="function"==typeof e.valueOf?e.valueOf():e;e=n(t)?t+"":t}if("string"!=typeof e)return 0===e?e:+e;e=e.replace(p,"");var o=y.test(e);return o||h.test(e)?g(e.slice(2),o?2:8):m.test(e)?f:+e}function c(e,t){return e===t||!!(16&e.compareDocumentPosition(t))}function l(e){e.setAttribute("aria-hidden",!0)}var a=function(e){var t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:document;return[].slice.call(t.querySelectorAll(e))},s="undefined"!=typeof window?window:"undefined"!=typeof global?global:"undefined"!=typeof self?self:{},u="function"==typeof Symbol&&"symbol"==typeof Symbol.iterator?function(e){return typeof e}:function(e){return e&&"function"==typeof Symbol&&e.constructor===Symbol&&e!==Symbol.prototype?"symbol":typeof e},d=(function(){function e(e){this.value=e}function t(t){function n(i,r){try{var c=t[i](r),l=c.value;l instanceof e?Promise.resolve(l.value).then(function(e){n("next",e)},function(e){n("throw",e)}):o(c.done?"return":"normal",c.value)}catch(e){o("throw",e)}}function o(e,t){switch(e){case"return":i.resolve({value:t,done:!0});break;case"throw":i.reject(t);break;default:i.resolve({value:t,done:!1})}(i=i.next)?n(i.key,i.arg):r=null}var i,r;this._invoke=function(e,t){return new Promise(function(o,c){var l={key:e,arg:t,resolve:o,reject:c,next:null};r?r=r.next=l:(i=r=l,n(e,t))})},"function"!=typeof t.return&&(this.return=void 0)}"function"==typeof Symbol&&Symbol.asyncIterator&&(t.prototype[Symbol.asyncIterator]=function(){return this}),t.prototype.next=function(e){return this._invoke("next",e)},t.prototype.throw=function(e){return this._invoke("throw",e)},t.prototype.return=function(e){return this._invoke("return",e)}}(),"Expected a function"),f=NaN,v="[object Symbol]",p=/^\s+|\s+$/g,m=/^[-+]0x[0-9a-f]+$/i,y=/^0b[01]+$/i,h=/^0o[0-7]+$/i,g=parseInt,b="object"==u(s)&&s&&s.Object===Object&&s,E="object"==("undefined"==typeof self?"undefined":u(self))&&self&&self.Object===Object&&self,S=b||E||Function("return this")(),_=Object.prototype.toString,k=Math.max,w=Math.min,L=function(){return S.Date.now()},x=function(e,t,o){function i(t){var n=v,o=p;return v=p=void 0,b=t,y=e.apply(o,n)}function c(e){return b=e,h=setTimeout(s,t),E?i(e):y}function l(e){var n=t-(e-g);return S?w(n,m-(e-b)):n}function a(e){var n=e-g;return void 0===g||n>=t||n<0||S&&e-b>=m}function s(){var e=L();if(a(e))return u(e);h=setTimeout(s,l(e))}function u(e){return h=void 0,_&&v?i(e):(v=p=void 0,y)}function f(){var e=L(),n=a(e);if(v=arguments,p=this,g=e,n){if(void 0===h)return c(g);if(S)return h=setTimeout(s,t),i(g)}return void 0===h&&(h=setTimeout(s,t)),y}var v,p,m,y,h,g,b=0,E=!1,S=!1,_=!0;if("function"!=typeof e)throw new TypeError(d);return t=r(t)||0,n(o)&&(E=!!o.leading,m=(S="maxWait"in o)?k(r(o.maxWait)||0,t):m,_="trailing"in o?!!o.trailing:_),f.cancel=function(){void 0!==h&&clearTimeout(h),b=0,v=g=p=h=void 0},f.flush=function(){return void 0===h?y:u(L())},f},A=function(e,t){var n=arguments.length>2&&void 0!==arguments[2]?arguments[2]:{},o=n.classToRemove,i=void 0===o?"ecl-context-nav__item--over-limit":o,r=n.hiddenElementsSelector,c=void 0===r?".ecl-context-nav__item--over-limit":r,l=n.context,s=void 0===l?document:l;e&&(a(c,s).forEach(function(e){e.classList.remove(i)}),t.parentNode.removeChild(t))},C=function e(t){var n=arguments.length>1&&void 0!==arguments[1]?arguments[1]:{},o=n.context,i=void 0===o?document:o,r=n.forceClose,c=void 0!==r&&r,l=n.closeSiblings,a=void 0!==l&&l,s=n.siblingsSelector,u=void 0===s?"[aria-controls][aria-expanded]":s;if(t){var d=document.getElementById(t.getAttribute("aria-controls"));if(d){var f=!0===c||"true"===t.getAttribute("aria-expanded");t.setAttribute("aria-expanded",!f),d.setAttribute("aria-hidden",f),!0===a&&Array.prototype.slice.call(i.querySelectorAll(u)).filter(function(e){return e!==t}).forEach(function(t){e(t,{context:i,forceClose:!0})})}}},q=t(function(e,t){!function(t,n){e.exports=n()}(0,function(){function e(e,t){var n=void 0!==t?t:{};this.version="2.0.8",this.userAgent=window.navigator.userAgent||"no `userAgent` provided by the browser",this.props={noStyles:n.noStyles||!1,stickyBitStickyOffset:n.stickyBitStickyOffset||0,parentClass:n.parentClass||"js-stickybit-parent",scrollEl:n.scrollEl||window,stickyClass:n.stickyClass||"js-is-sticky",stuckClass:n.stuckClass||"js-is-stuck",useStickyClasses:n.useStickyClasses||!1,verticalPosition:n.verticalPosition||"top"};var o=this.props;o.positionVal=this.definePosition()||"fixed";var i=o.verticalPosition,r=o.noStyles,c=o.positionVal;this.els="string"==typeof e?document.querySelectorAll(e):e,"length"in this.els||(this.els=[this.els]),this.instances=[];for(var l=0;l<this.els.length;l+=1){var a=this.els[l],s=a.style;if("top"!==i||r||(s[i]=o.stickyBitStickyOffset+"px"),"fixed"!==c&&!1===o.useStickyClasses)s.position=c;else{"fixed"!==c&&(s.position=c);var u=this.addInstance(a,o);this.instances.push(u)}}return this}return e.prototype.definePosition=function(){for(var e=["","-o-","-webkit-","-moz-","-ms-"],t=document.head.style,n=0;n<e.length;n+=1)t.position=e[n]+"sticky";var o="fixed";return void 0!==t.position&&(o=t.position),t.position="",o},e.prototype.addInstance=function(e,t){var n=this,o={el:e,parent:e.parentNode,props:t},i=o.props;o.parent.className+=" "+t.parentClass;var r=i.scrollEl;return o.isWin=r===window,o.isWin||(r=this.getClosestParent(o.el,r)),this.computeScrollOffsets(o),o.state="default",o.stateContainer=function(){n.manageState(o)},r.addEventListener("scroll",o.stateContainer),o},e.prototype.getClosestParent=function(e,t){var n=document.querySelector(t),o=e;if(o.parentElement===n)return n;for(;o.parentElement!==n;)o=o.parentElement;return n},e.prototype.computeScrollOffsets=function(e){var t=e,n=t.props,o=t.parent,i=t.isWin,r=0,c=o.getBoundingClientRect().top;return i||"fixed"!==n.positionVal||(r=n.scrollEl.getBoundingClientRect().top,c=o.getBoundingClientRect().top-r),t.offset=r+n.stickyBitStickyOffset,t.stickyStart=c,t.stickyStop=t.stickyStart+o.offsetHeight-(t.el.offsetHeight-t.offset),t},e.prototype.toggleClasses=function(e,t,n){var o=e,i=o.className.split(" ");n&&-1===i.indexOf(n)&&i.push(n);var r=i.indexOf(t);-1!==r&&i.splice(r,1),o.className=i.join(" ")},e.prototype.manageState=function(e){var t=e,n=t.el,o=t.props,i=t.state,r=t.stickyStart,c=t.stickyStop,l=n.style,a=o.noStyles,s=o.positionVal,u=o.scrollEl,d=o.stickyClass,f=o.stuckClass,v=o.verticalPosition,p=u.requestAnimationFrame;t.isWin&&void 0!==p||(p=function(e){e()});var m=this.toggleClasses,y=t.isWin?u.scrollY||u.pageYOffset:u.scrollTop,h=y<=r&&"sticky"===i,g=y>=c&&"sticky"===i;return y>r&&y<c&&("default"===i||"stuck"===i)?(t.state="sticky",p(function(){m(n,f,d),l.position=s,a||(l.bottom="",l[v]=o.stickyBitStickyOffset+"px")})):h?(t.state="default",p(function(){m(n,d),"fixed"===s&&(l.position="")})):g&&(t.state="stuck",p(function(){m(n,d,f),"fixed"!==s||a||(l.top="",l.bottom="0",l.position="absolute")})),t},e.prototype.removeInstance=function(e){var t=e.el,n=e.props,o=this.toggleClasses;t.style.position="",t.style[n.verticalPosition]="",o(t,n.stickyClass),o(t,n.stuckClass),o(t.parentNode,n.parentClass)},e.prototype.cleanup=function(){for(var e=0;e<this.instances.length;e+=1){var t=this.instances[e];t.props.scrollEl.removeEventListener("scroll",t.stateContainer),this.removeInstance(t)}this.manageState=!1,this.instances=[]},function(t,n){return new e(t,n)}})}),T=t(function(e,t){!function(t,n){e.exports=n(t)}(void 0!==s?s:s.window||s.global,function(e){var t,n,o,i,r,c,l,a={},s="querySelector"in document&&"addEventListener"in e&&"classList"in document.createElement("_"),u=[],d={selector:"[data-gumshoe] a",selectorHeader:"[data-gumshoe-header]",container:e,offset:0,activeClass:"active",scrollDelay:!1,callback:function(){}},f=function(e,t,n){if("[object Object]"===Object.prototype.toString.call(e))for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&t.call(n,e[o],o,e);else for(var i=0,r=e.length;i<r;i++)t.call(n,e[i],i,e)},v=function e(){var t={},n=!1,o=0,i=arguments.length;for("[object Boolean]"===Object.prototype.toString.call(arguments[0])&&(n=arguments[0],o++);o<i;o++)!function(o){for(var i in o)Object.prototype.hasOwnProperty.call(o,i)&&(n&&"[object Object]"===Object.prototype.toString.call(o[i])?t[i]=e(!0,t[i],o[i]):t[i]=o[i])}(arguments[o]);return t},p=function(e){return Math.max(e.scrollHeight,e.offsetHeight,e.clientHeight)},m=function(){return Math.max(document.body.scrollHeight,document.documentElement.scrollHeight,document.body.offsetHeight,document.documentElement.offsetHeight,document.body.clientHeight,document.documentElement.clientHeight)},y=function(e){var n=0;if(e.offsetParent)do{n+=e.offsetTop,e=e.offsetParent}while(e);else n=e.offsetTop;return(n=n-r-t.offset)>=0?n:0},h=function(t){var n=t.getBoundingClientRect();return n.top>=0&&n.left>=0&&n.bottom<=(e.innerHeight||document.documentElement.clientHeight)&&n.right<=(e.innerWidth||document.documentElement.clientWidth)},g=function(){u.sort(function(e,t){return e.distance>t.distance?-1:e.distance<t.distance?1:0})};a.setDistances=function(){o=m(),r=i?p(i)+y(i):0,f(u,function(e){e.distance=y(e.target)}),g()};var b=function(){var e=document.querySelectorAll(t.selector);f(e,function(e){if(e.hash){var t=document.querySelector(e.hash);t&&u.push({nav:e,target:t,parent:"li"===e.parentNode.tagName.toLowerCase()?e.parentNode:null,distance:0})}})},E=function(){c&&(c.nav.classList.remove(t.activeClass),c.parent&&c.parent.classList.remove(t.activeClass))},S=function(e){E(),e.nav.classList.add(t.activeClass),e.parent&&e.parent.classList.add(t.activeClass),t.callback(e),c={nav:e.nav,parent:e.parent}};a.getCurrentNav=function(){var n=e.pageYOffset;if(e.innerHeight+n>=o&&h(u[0].target))return S(u[0]),u[0];for(var i=0,r=u.length;i<r;i++){var c=u[i];if(c.distance<=n)return S(c),c}E(),t.callback()};var _=function(){f(u,function(e){e.nav.classList.contains(t.activeClass)&&(c={nav:e.nav,parent:e.parent})})};a.destroy=function(){t&&(t.container.removeEventListener("resize",w,!1),t.container.removeEventListener("scroll",w,!1),u=[],t=null,n=null,o=null,i=null,r=null,c=null,l=null)};var k=function(e){window.clearTimeout(n),n=setTimeout(function(){a.setDistances(),a.getCurrentNav()},66)},w=function(e){n||(n=setTimeout(function(){n=null,"scroll"===e.type&&a.getCurrentNav(),"resize"===e.type&&(a.setDistances(),a.getCurrentNav())},66))};return a.init=function(e){s&&(a.destroy(),t=v(d,e||{}),i=document.querySelector(t.selectorHeader),b(),0!==u.length&&(_(),a.setDistances(),a.getCurrentNav(),t.container.addEventListener("resize",w,!1),t.scrollDelay?t.container.addEventListener("scroll",k,!1):t.container.addEventListener("scroll",w,!1)))},a})}),O=function(e,t){return function(n){if(e&&e.hasAttribute("aria-haspopup")){var o=e.getAttribute("aria-haspopup");""!==o&&"true"!==o||(n.preventDefault(),C(e,{context:t,closeSiblings:!0}))}}},j=function(e,t){return function(n){var o=e.parentElement,i=o.previousElementSibling||o.parentElement.lastElementChild,r=o.nextElementSibling||o.parentElement.firstElementChild;if(!n.metaKey&&!n.altKey)switch(n.keyCode){case 13:case 32:O(n.currentTarget,t)(n);break;case 37:case 38:n.preventDefault(),i.querySelector("a").focus();break;case 39:case 40:n.preventDefault(),r.querySelector("a").focus()}}},N=function(e,t){var n=arguments.length>2&&void 0!==arguments[2]?arguments[2]:{},o=n.classToRemove,i=void 0===o?"ecl-timeline__item--over-limit":o,r=n.hiddenElementsSelector,c=void 0===r?".ecl-timeline__item--over-limit":r;e&&(Array.prototype.slice.call(e.querySelectorAll(c)).forEach(function(e){e.classList.remove(i)}),t.parentNode.removeChild(t))};return e.accordions=function(){function e(e){var t=document.getElementById(e.getAttribute("aria-controls"));e.setAttribute("aria-expanded","false"),t.setAttribute("aria-hidden","true")}function t(e){var t=document.getElementById(e.getAttribute("aria-controls"));e.setAttribute("tabindex",0),e.setAttribute("aria-expanded","true"),t.setAttribute("aria-hidden","false")}function n(n){"true"!==n.getAttribute("aria-expanded")?t(n):e(n)}function o(e,t){e[t].focus()}function i(e){n(e.currentTarget)}function r(e){var t=e.currentTarget,i=e.metaKey||e.altKey,r=t.parentNode.parentNode,c=a(p,r),l=[].indexOf.call(c,t);if(!i)switch(e.keyCode){case 13:case 32:n(t),e.preventDefault();break;case 37:case 38:o(c,0===l?c.length-1:l-1),e.preventDefault();break;case 39:case 40:o(c,l<c.length-1?l+1:0),e.preventDefault()}}function c(e){a(p,e).forEach(function(e){e.addEventListener("click",i),e.addEventListener("keydown",r)})}function l(e){a(p,e).forEach(function(e){e.removeEventListener("click",i),e.removeEventListener("keydown",r)})}function s(){m.length&&m.forEach(function(e){c(e)})}var u=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},d=u.selector,f=void 0===d?".ecl-accordion":d,v=u.headerSelector,p=void 0===v?".ecl-accordion__header":v;if(!("querySelector"in document&&"addEventListener"in window&&document.documentElement.classList))return null;var m=a(f);return s(),{init:s,destroy:function(){m.forEach(function(e){l(e)})}}},e.carousels=function(){function e(){return y.querySelector(".ecl-carousel__item").offsetWidth}function t(e){h[m].classList.remove("ecl-carousel__item--showing"),m=(e+h.length)%h.length,h[m].classList.add("ecl-carousel__item--showing")}function n(){var t=e(),n="translate3d("+-m*t+"px, 0, 0)";g.style.MozTransform=n,g.style.msTransform=n,g.style.OTransform=n,g.style.WebkitTransform=n,g.style.transform=n}function o(){y.querySelector(".ecl-carousel__meta-slide").textContent=m+1+" / "+h.length}function i(){var e=a("[data-image]");e&&e.forEach(function(e){return e.style.display="none"}),y.querySelector('[data-image="'+m+'"]').style.display="block"}function r(){t(m-1),n(),o(),i()}function c(){t(m+1),n(),o(),i()}function l(){var e=document.createElement("ul");e.className="ecl-carousel__controls ecl-list--unstyled",e.innerHTML='\n      <li>\n        <button type="button" class="ecl-icon ecl-icon--left ecl-carousel__button ecl-carousel__button--previous">\n          <span class="ecl-u-sr-only">Previous</span></button>\n      </li>\n      <li>\n        <button type="button" class="ecl-icon ecl-icon--right ecl-carousel__button ecl-carousel__button--next">\n          <span class="ecl-u-sr-only">Next</span>\n        </button>\n      </li>\n    ',e.querySelector(".ecl-carousel__button--previous",".ecl-carousel__controls").addEventListener("click",r),e.querySelector(".ecl-carousel__button--next",".ecl-carousel__controls").addEventListener("click",c),y.querySelector(".ecl-carousel__list-wrapper").appendChild(e)}function s(){var e=y.querySelector(".ecl-carousel__controls");y.querySelector(".ecl-carousel__list-wrapper").removeChild(e)}function u(){var e=document.createElement("div");e.setAttribute("aria-live","polite"),e.setAttribute("aria-atomic","true"),e.classList.add("ecl-carousel__meta-slide"),y.querySelector(".ecl-carousel__live-region").appendChild(e)}function d(){var e=y.querySelector(".ecl-carousel__meta-slide");y.querySelector(".ecl-carousel__live-region").removeChild(e)}function f(){l(),u(),t(0),o(),i(),window.addEventListener("resize",b)}var v=(arguments.length>0&&void 0!==arguments[0]?arguments[0]:{}).selectorId,p=void 0===v?"ecl-carousel":v;if(!("querySelector"in document&&"addEventListener"in window))return null;var m=0,y=document.getElementById(p),h=a(".ecl-carousel__item",y),g=y.querySelector(".ecl-carousel__list"),b=function(){return x(function(){n()},100,{maxWait:300})()};return f(),{init:f,destroy:function(){s(),d(),window.removeEventListener("resize",b)}}},e.contextualNavs=function(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},t=e.selector,n=void 0===t?".ecl-context-nav":t,o=e.buttonSelector,i=void 0===o?".ecl-context-nav__more":o,r=e.hiddenElementsSelector,c=void 0===r?".ecl-context-nav__item--over-limit":r,l=e.classToRemove,s=void 0===l?"ecl-context-nav__item--over-limit":l,u=e.context,d=void 0===u?document:u;a(n,d).forEach(function(e){var t=d.querySelector(i);t&&t.addEventListener("click",function(){return A(e,t,{classToRemove:s,hiddenElementsSelector:c})})})},e.dropdown=function(e){var t=Array.prototype.slice.call(document.querySelectorAll(e));document.addEventListener("click",function(n){t.forEach(function(t){if(!c(t,n.target)){var o=document.querySelector(e+" > [aria-expanded=true]"),i=document.querySelector(e+" > [aria-hidden=false]");i&&(o.setAttribute("aria-expanded",!1),i.setAttribute("aria-hidden",!0))}})})},e.dialogs=function(){function e(){m.setAttribute("aria-hidden",!0),y.setAttribute("aria-hidden",!0),b&&b.focus()}function t(t){switch(t.keyCode){case 9:if(1===g.length){t.preventDefault();break}t.shiftKey?document.activeElement===E&&(t.preventDefault(),S.focus()):document.activeElement===S&&(t.preventDefault(),E.focus());break;case 27:e()}}function n(){m.setAttribute("aria-hidden",!1),y.setAttribute("aria-hidden",!1),b=document.activeElement,E.focus(),y.addEventListener("click",e),m.addEventListener("keydown",t)}function o(t){t.forEach(function(e){return e.addEventListener("click",n)}),a(".ecl-message__dismiss").forEach(function(t){t.addEventListener("click",e)})}function i(t){t.forEach(function(e){return e.removeEventListener("click",n)}),a(".ecl-message__dismiss").forEach(function(t){t.removeEventListener("click",e)})}function r(){p.length&&o(p)}var c=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},l=c.triggerElementsSelector,s=void 0===l?"[data-ecl-dialog]":l,u=c.dialogWindowId,d=void 0===u?"ecl-dialog":u,f=c.dialogOverlayId,v=void 0===f?"ecl-overlay":f;if(!("querySelector"in document&&"addEventListener"in window))return null;var p=a(s),m=document.getElementById(d),y=document.getElementById(v);if(!y){var h=document.createElement("div");h.setAttribute("id","ecl-overlay"),h.setAttribute("class","ecl-dialog__overlay"),h.setAttribute("aria-hidden","true"),document.body.appendChild(h),y=h}var g=[].slice.call(a('\n        a[href],\n        area[href],\n        input:not([disabled]),\n        select:not([disabled]),\n        textarea:not([disabled]),\n        button:not([disabled]),\n        [tabindex="0"]\n      ',m)),b=null,E=g[0],S=g[g.length-1];return r(),{init:r,destroy:function(){i(p)}}},e.toggleExpandable=C,e.initExpandables=function(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:"[aria-controls][aria-expanded]",t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:document;Array.prototype.slice.call(t.querySelectorAll(e)).forEach(function(e){return e.addEventListener("click",function(n){C(e,{context:t}),n.preventDefault()})})},e.fileUploads=function(){function e(e,t){if(0!==t.length){for(var n="",o=0;o<t.length;o+=1){var i=t[o];"name"in i&&(o>0&&(n+=", "),n+=i.name)}e.innerHTML=n}}function t(t){"files"in t.target&&a(v,t.target.parentNode).forEach(function(n){e(n,t.target.files)})}function n(e){var t=e.metaKey||e.altKey;a(d,e.target.parentNode).forEach(function(n){if(!t)switch(e.keyCode){case 13:case 32:e.preventDefault(),n.click()}})}function o(e){a(d,e).forEach(function(e){e.addEventListener("change",t)}),a(m,e).forEach(function(e){e.addEventListener("keydown",n)})}function i(e){a(d,e).forEach(function(e){e.removeEventListener("change",t)}),a(m,e).forEach(function(e){e.removeEventListener("keydown",n)})}function r(){y.length&&y.forEach(function(e){o(e)})}var c=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},l=c.selector,s=void 0===l?".ecl-file-upload":l,u=c.inputSelector,d=void 0===u?".ecl-file-upload__input":u,f=c.valueSelector,v=void 0===f?".ecl-file-upload__value":f,p=c.browseSelector,m=void 0===p?".ecl-file-upload__browse":p;if(!("querySelector"in document&&"addEventListener"in window&&document.documentElement.classList))return null;var y=a(s);return r(),{init:r,destroy:function(){y.forEach(function(e){i(e)})}}},e.eclLangSelectPages=function(){function e(e){if(!e)return null;var t=a(l,e)[0];return e.classList.contains(r)?a(u,e)[0].offsetLeft+t.offsetWidth<e.offsetWidth&&e.classList.remove(r):t&&t.offsetLeft+t.offsetWidth>e.offsetWidth&&e.classList.add(r),!0}var t=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},n=t.selector,o=void 0===n?".ecl-lang-select-page":n,i=t.toggleClass,r=void 0===i?"ecl-lang-select-page--dropdown":i,c=t.listSelector,l=void 0===c?".ecl-lang-select-page__list":c,s=t.dropdownSelector,u=void 0===s?".ecl-lang-select-page__dropdown":s,d=t.dropdownOnChange,f=void 0===d?void 0:d;if(!("querySelector"in document&&"addEventListener"in window&&document.documentElement.classList))return null;var v=a(o);return v.forEach(function(t){if(e(t),f){var n=a(u,t)[0];n&&n.addEventListener("change",f)}}),void window.addEventListener("resize",x(function(){v.forEach(e)},100,{maxWait:300}))},e.initMessages=function(){Array.prototype.slice.call(document.getElementsByClassName("ecl-message__dismiss")).forEach(function(e){return e.addEventListener("click",function(){return l(e.parentElement)})})},e.navigationInpages=function(){function e(){q(r,{useStickyClasses:!0})}function t(){T.init({selector:l,activeClass:s,offset:v,callback:function(e){e&&(document.querySelector(d).innerHTML=e.nav.innerHTML)}})}function n(){e(),t()}var o=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},i=o.stickySelector,r=void 0===i?".ecl-navigation-inpage":i,c=o.spySelector,l=void 0===c?".ecl-navigation-inpage__link":c,a=o.spyClass,s=void 0===a?"ecl-navigation-inpage__link--is-active":a,u=o.spyTrigger,d=void 0===u?".ecl-navigation-inpage__trigger":u,f=o.spyOffset,v=void 0===f?20:f;return"querySelector"in document&&"addEventListener"in window&&document.documentElement.classList?(n(),{init:n}):null},e.megamenu=function(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},t=e.selector,n=void 0===t?".ecl-navigation-menu":t,o=e.toggleSelector,i=void 0===o?".ecl-navigation-menu__toggle":o,r=e.listSelector,c=void 0===r?".ecl-navigation-menu__root":r,l=e.linkSelector,s=void 0===l?".ecl-navigation-menu__link":l;a(n).forEach(function(e){var t=e.querySelector(i);t&&t.addEventListener("click",function(){return C(t,{context:e})});var n=e.querySelector(c);a(s,n).forEach(function(e){e.addEventListener("click",O(e,n)),e.addEventListener("keydown",j(e,n))})})},e.eclTables=function(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:null,t=null===e?document.getElementsByClassName("ecl-table"):e;[].forEach.call(t,function(e){for(var t=[],n="",o=0,i=[],r=e.querySelectorAll("tbody tr"),c=e.querySelectorAll("thead tr th"),l=e.querySelectorAll("thead tr")[0].querySelectorAll("th").length-1,a=e.querySelectorAll("tbody tr")[0].querySelectorAll("td").length,s=-1,u=0;u<c.length;u+=1)c[u].getAttribute("colspan")&&(s=u),t[u]=[],t[u]=c[u].textContent;if(-1!==s){n=t.splice(s,1),o=s,i=e.querySelectorAll("th[colspan]")[0].getAttribute("colspan");for(var d=0;d<i;d+=1)t.splice(o+d,0,t[l+d]),t.splice(l+1+d,1)}[].forEach.call(r,function(e){for(var o=0;o<a;o+=1)if(""===t[o]||" "===t[o]?e.querySelectorAll("td")[o].setAttribute("class","ecl-table__heading"):e.querySelectorAll("td")[o].setAttribute("data-th",t[o]),-1!==s){var r=e.querySelectorAll("td")[s];r.setAttribute("class","ecl-table__group-label"),r.setAttribute("data-th-group",n);for(var c=1;c<i;c+=1)e.querySelectorAll("td")[s+c].setAttribute("class","ecl-table__group_element")}})})},e.tabs=function(){function e(e){var t=!(arguments.length>1&&void 0!==arguments[1])||arguments[1],n=a(d+" li",e.parentElement.parentElement),o=a(v,e.parentElement.parentElement);n.forEach(function(e){e.setAttribute("tabindex",-1),e.removeAttribute("aria-selected")}),o.forEach(function(e){e.setAttribute("aria-hidden","true")}),e.setAttribute("tabindex",0),e.setAttribute("aria-selected","true"),t&&e.focus(),document.getElementById(e.getAttribute("aria-controls")).removeAttribute("aria-hidden")}function t(t){e(t.currentTarget),t.preventDefault()}function n(t){var n=t.currentTarget,o=n.previousElementSibling||n.parentElement.lastElementChild,i=n.nextElementSibling||n.parentElement.firstElementChild;if(!t.metaKey&&!t.altKey)switch(t.keyCode){case 37:case 38:e(o),t.preventDefault();break;case 39:case 40:e(i),t.preventDefault()}}function o(e){a(m,e).forEach(function(e){e.addEventListener("click",t),e.addEventListener("keydown",n)})}function i(e){a(m,e).forEach(function(e){e.removeEventListener("click",t),e.removeEventListener("keydown",n)})}function r(){y.forEach(o)}var c=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},l=c.selector,s=void 0===l?".ecl-tabs":l,u=c.tablistSelector,d=void 0===u?".ecl-tabs__tablist":u,f=c.tabpanelSelector,v=void 0===f?".ecl-tabs__tabpanel":f,p=c.tabelementsSelector,m=void 0===p?d+" li":p;if(!("querySelector"in document&&"addEventListener"in window&&document.documentElement.classList))return null;var y=a(s);return r(),{init:r,destroy:function(){y.forEach(i)}}},e.timelines=function(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},t=e.selector,n=void 0===t?".ecl-timeline":t,o=e.buttonSelector,i=void 0===o?".ecl-timeline__button":o,r=e.hiddenElementsSelector,c=void 0===r?".ecl-timeline__item--over-limit":r,l=e.classToRemove,a=void 0===l?"ecl-timeline__item--over-limit":l,s=e.context,u=void 0===s?document:s;Array.prototype.slice.call(u.querySelectorAll(n)).forEach(function(e){var t=u.querySelector(i);t&&t.addEventListener("click",function(){return N(e,t,{classToRemove:a,hiddenElementsSelector:c})})})},e}({});
